#define ALPHA 26
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct clit {
	char* nome;
	int id;
	float rating;
	struct clit* proximo;
};

struct cadastro {
	struct clit** vetor;
};
typedef struct cadastro Cadastro;
typedef struct clit Clit;


Cadastro* criaCadastro(void);
Clit* insereNo(Clit* head, Clit* no);
int insere(Cadastro* cad, char* nome, int id, float rating);
void exibeCadastro(Cadastro* cad);
float averageRating(Cadastro* cad);
void liberaCadastro(Cadastro* cad);

int main(void) {
	Cadastro* cad = criaCadastro();
	insere(cad, "Fiona", 101, 2.0);	
	insere(cad, "Zelda", 102, 5.0);
	insere(cad, "Ada Lovelace", 103, 4.5);
	insere(cad, "Fred", 104, 3.0);
	insere(cad, "Ahsoka", 105, 5.0);
	insere(cad, "Fani", 106, 4.0);
	exibeCadastro(cad);
	printf("\n\n AVERAGE RATING: %f", averageRating(cad));
	return 0;
}




Cadastro* criaCadastro(void){
	Cadastro* cad = (Cadastro*)malloc(sizeof(Cadastro));
	if (cad == NULL) exit(1);
	cad->vetor = (Clit**)malloc(sizeof(Clit*) * ALPHA);
	if (cad->vetor == NULL) exit(1);
	for (int i = 0; i < ALPHA; i++) {
		cad->vetor[i] = NULL;
	}
	return cad;
}

Clit* insereNo(Clit* head, Clit* no) {
	no->proximo = head;
	return no;
}

int insere(Cadastro* cad, char* nome, int id, float rating) {
	Clit* pessoa = (Clit*)malloc(sizeof(Clit));
	if (pessoa == NULL) return 0;
	pessoa->id = id;
	pessoa->rating = rating;
	pessoa->nome = (char*)malloc(strlen(nome)+1);
	if (pessoa->nome == NULL) return 0;
	strcpy(pessoa->nome, nome);
	int index = nome[0] - 'A';
	cad->vetor[index] = insereNo(cad->vetor[index], pessoa);
	return 1;
}

void exibeCadastro(Cadastro* cad) {
	for (int i = 0; i < ALPHA; i++) {
		printf("%c:\n", 'A' + i);
		for (Clit* p = cad->vetor[i]; p != NULL; p = p->proximo) {
			printf("  %s %d %f \n", p->nome, p->id, p->rating);
		}
	}
}

float averageRating(Cadastro* cad) {
	int counter = 0;
	float somatorio = 0.0f;
	for (int i = 0; i < ALPHA; i++) {
		for (Clit* p = cad->vetor[i]; p != NULL; p = p->proximo) {
			somatorio += p->rating;
			counter += 1;
		}
	}
	return (float)somatorio / counter;
}

void liberaCadastro(Cadastro* cad) {
	for (int i = 0; i < ALPHA; i++) {
		for (Clit* p = cad->vetor[i]; p != NULL; p = p->proximo) {
			free(p->nome);
		}
	}
}
