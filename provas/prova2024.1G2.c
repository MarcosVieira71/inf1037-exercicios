//NOME: MARCOS PAULO MARINHO VIEIRA
//MATRICULA: 2320466 TURMA:33A PROF: WALDEMAR CELES

#define _CRT_SECURE_NO_DEPRECATE
#define ALPHA 26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
struct node {
	char* nome;
	int num;
	Node* prox;
};

typedef struct agenda Agenda;
struct agenda {
	Node* info[ALPHA];
};

Agenda* criaAgenda(void);
Node* insereNode(Node* head, char* nome, int telefone);
int inserePessoa(Agenda* a, char* nome, int telefone);
void exibeAgenda(Agenda* a, char letra);
void liberaAgenda(Agenda* a);

int main(void) {
	
	Agenda* a = criaAgenda();
	if (a == NULL) {
		exit(1);
	}

	int t1 = inserePessoa(a, "Fred", 50000005);
	if (t1 == 0) exit(1);
	
	int t2 = inserePessoa(a, "Zoe", 80000008);
	if (t2 == 0) exit(1);
	
	int t3 = inserePessoa(a, "Ada", 40000004);
	if (t3 == 0) exit(1);
	
	int t4 = inserePessoa(a, "Frida", 60000006);
	if (t4 == 0) exit(1);
	
	int t5 = inserePessoa(a, "Yoda", 90000009);
	if (t5 == 0) exit(1);
	
	int t6 = inserePessoa(a, "Feynman", 70000007);
	if (t6 == 0) exit(1);


	exibeAgenda(a, 'A');
	exibeAgenda(a, 'F');
	exibeAgenda(a, 'Y');
	exibeAgenda(a, 'Z');

	liberaAgenda(a);
	return 0;
}

Agenda* criaAgenda(void) {
	Agenda* agenda = (Agenda*)malloc(sizeof(Agenda));
	
	if (agenda == NULL) {
		return NULL;
	}
	
	for (int i = 0; i < ALPHA; i++) {
		agenda->info[i] = NULL;
	}
	return agenda;
}

Node* insereNode(Node* head, char* nome, int telefone) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return NULL;

	int tamanhoNome = strlen(nome);
	newNode->num = telefone;

	newNode->nome = (char*)malloc(sizeof(char) * tamanhoNome + 1);
	if (newNode->nome == NULL) {
		free(newNode);
		return NULL;
	}
	strcpy(newNode->nome, nome);
	
	newNode->prox = head;
	
	return newNode;
}

int inserePessoa(Agenda* a, char* nome, int telefone) {
	int pos = nome[0] - 'A';
	a->info[pos] = insereNode(a->info[pos], nome, telefone); 
	if (a->info[pos] != NULL) return 1;
	else return 0;
}

void exibeAgenda(Agenda* a, char letra) {
	Node* pos = a->info[letra - 'A'];
	if (pos == NULL) printf("Nao existem pessoas com a letra %c na agenda" , letra);
	else {
		printf("%c:\n", letra);
		for (; pos != NULL; pos = pos->prox) {
			printf("   %s: %d\n", pos->nome, pos->num);
		}
	}
	printf("\n");
}

void liberaAgenda(Agenda* a) {
	for (int i = 0; i < ALPHA; i++) {
		Node* p = a->info[i];
		while (p != NULL) {
			Node* t = p->prox;
			free(p->nome);
			free(p);
			p = t;
		}
	}
}