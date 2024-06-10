#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
	int data;
	struct lista* proximo;
};

struct aluninhos {
	char nome[100];
	int mat;
	float nota;
	struct aluninhos* proximo;
};

struct aluninhosDinamicos{
	char* nome;
	int mat;
	float nota;
	struct aluninhosDinamicos* proximo;
};

typedef struct aluninhosDinamicos AlunosDinamicos;
typedef struct aluninhos Alunos;
typedef struct lista Lista;

int igual(Lista* l1, Lista* l2);
int igualRecursiva(Lista* l1, Lista* l2);
Lista* insere(Lista* l, int x);
void imprime(Lista* l);
Lista* copia(Lista* l);
Lista* copiaRecursiva(Lista* l);
Alunos* insereAluno(Alunos* l, char* nome, int mat, float nota);



int main(void) {
	Lista* l1 = NULL;
	l1 = insere(l1, 10);
	l1 = insere(l1, 11);
	l1 = insere(l1, 14);
	imprime(l1);
	printf("ACABOU UEPAAAA\n");
	Lista* l2 = copia(l1);
	imprime(l2);

	return 0;
}

int igual(Lista* l1, Lista* l2) {
	Lista* p1 = l1;
	Lista* p2 = l2;
	while (p1 != NULL && p2 != NULL) {
		if (p1->data != p2->data) return 0;
		p1 = p1->proximo;
		p2 = p2->proximo;

	}
	return p1 == p2;
}

int igualRecursiva(Lista* l1, Lista* l2) {
	if (l1 == NULL && l2 == NULL) {
		return 1;
	}
	else if (l1 == NULL || l2 == NULL) return 0;
	else return l1->data == l2->data && igualRecursiva(l1->proximo, l2->proximo);
}

Lista* insere(Lista* l, int x) {
	Lista* p = (Lista*)malloc(sizeof(Lista));
	if (p == NULL) exit(1);
	p->data= x;
	p->proximo = l;
	return p;
}

void imprime(Lista* l) {
	for (Lista* p = l; p != NULL; p = p->proximo) printf("%d\n", p->data);
}

Lista* copia(Lista* l) {
	Lista* inicio = NULL;
	Lista* fim = NULL;
	inicio = l;
	fim = l;
	for (Lista* p = l->proximo; p != NULL; p = p->proximo) {
		Lista* q = (Lista*)malloc(sizeof(Lista));
		if (q == NULL) exit(1);
		q->data = p->data;
		q->proximo = NULL;
		fim->proximo = q;
		fim = q;
	}
	return inicio;
}

Lista* copiaRecursiva(Lista* l) {
	if (l == NULL) return NULL;
	else {
		Lista* p = (Lista*)malloc(sizeof(Lista)); 
		if (p == NULL) exit(1);
		p->data = l->data;
		p->proximo = copiaRecursiva(l->proximo);
		return p;
	}
}

Alunos* insereAluno(Alunos* l, char* nome, int mat, float nota) {
	Alunos* p = (Alunos*)malloc(sizeof(Alunos));
	if (p == NULL) exit(1);
	strcpy(p->nome, nome);
	p->mat = mat;
	p->nota = nota;
	p->proximo = l;
	return p;
}

AlunosDinamicos* insereAlunoDinamicos(AlunosDinamicos* l, char* nome, int mat, float nota) {
	AlunosDinamicos* p = (AlunosDinamicos*)malloc(sizeof(AlunosDinamicos));
	if (p == NULL) exit(1);
	p->nome = (char*)malloc(sizeof(strlen(nome) + 1));
	if (p->nome == NULL) exit(1);
	p->mat = mat;
	p->nota = nota;
	p->proximo = l;
	return p;
}
