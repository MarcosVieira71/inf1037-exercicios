#define _CRT_SECURE_NO_DEPRECATE
#define ALPHA 26
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;
struct funcionario {
	char nome[200];
	char data[11];
	float salario;
	struct funcionario* next;
};

unsigned int indice(char* nome);
int install(Funcionario* pFunc, Funcionario** pLista);
void imprimeFuncionarios(Funcionario** pLista);
int leUmFuncionario(FILE* arq, Funcionario** pFunc);
int removeUmFuncionario(char* nome, Funcionario** pLista);
void libera(Funcionario** pLista);


int main(void) {
	Funcionario* vetor[ALPHA];
	for (int i = 0; i < ALPHA; i++) {
		vetor[i] = NULL;
	}
	FILE* arq = fopen("teste22G3.txt", "r");
	if (arq == NULL) exit(1);
	while (leUmFuncionario(arq, vetor));
	int teste = removeUmFuncionario("Pedro Alves", vetor);
	imprimeFuncionarios(vetor);
	libera(vetor);
	fclose(arq);
	return 0;
}

unsigned int indice(char* nome) {
	unsigned int pos = nome[0] - 'A';
	return pos;
}

int install(Funcionario* pFunc, Funcionario** pLista) {
	unsigned int index= indice(pFunc->nome);
	if (pFunc == NULL) return 0;
	pFunc->next = pLista[index];
	pLista[index] = pFunc;
	return 1;
}

void imprimeFuncionarios(Funcionario** pLista) {
	for (int i = 0; i < ALPHA; i++) {
		if (pLista[i] != NULL) {
			printf("Trouxas com a letra %c:\n", i + 'A');
			for (Funcionario* p = pLista[i]; p != NULL; p = p->next) {
				printf("Funcionario %s contratado em %s ganha R$%.2f\n", p->nome, p->data, p->salario);
			}
		}
	}
}

int leUmFuncionario(FILE* arq, Funcionario** pFunc) {
	char nome[200];
	char data[11];
	float salario;
	int testeLeitura = fscanf(arq, " %[^,], %[^,], %f ", nome, data, &salario);
	if (testeLeitura < 3) return 0;
	Funcionario* func = (Funcionario*)malloc(sizeof(Funcionario));

	strcpy(func->nome, nome);
	strcpy(func->data, data);
	func->salario = salario;
	int insere = install(func, pFunc);
	return insere;
}

int removeUmFuncionario(char* nome, Funcionario** pLista) {
	int index = indice(nome);
	Funcionario* p = pLista[index];
	Funcionario* a = NULL;
	while (p != NULL) {
		if (strcmp(p->nome, nome) == 0) break;
		a = p;
		p = p->next;
	}
	if (p == NULL) return 0;
	a->next = p->next;
	free(p);
	return 1;	
}

void libera(Funcionario** pLista) {
	for (int i = 0; i < ALPHA; i++) {
		while (pLista[i] != NULL) {
			Funcionario* p = pLista[i]->next;
			free(pLista[i]);
			pLista[i] = p;
		}
	}
}