// *** utilidades.h ***//

//NOME: MARCOS VIEIRA
//TURMA: 33A MATRICULA: PROFESSOR: WALDEMAR CELES
int numBrancos(char* s);
char* montaNome(char* s);
char** leNomes(char* nomeDoArquivo, int* nElementos);
void gravaNomes(char* nomeDoArquivo, char** nomes, int numeroElementos);
void liberaVetor(char** vetorLiberar, int nElementos);

//*** utilidades.c ***//
//NOME: MARCOS VIEIRA
//TURMA: 33A MATRICULA: PROFESSOR: WALDEMAR CELES
#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int numBrancos(char* s) {
	if (*s == 0) {
		return 0;
	}
	else {
		if (*s == ' ') return 1 + numBrancos(s + 1);
		else return 0 + numBrancos(s + 1);
	}
}


char* ultimoNome(char* s) {
	int tamanhoNome = strlen(s);
	int lastSpace;
	for (lastSpace = tamanhoNome - 1; lastSpace >= 0; lastSpace--) {
		if (s[lastSpace] == ' ') {
			lastSpace = lastSpace + 1;
			break;
		}
	}
	char* ultimoNome = (s + lastSpace);
	return ultimoNome;
}

char* montaNome(char* nome) {
	int brancos = numBrancos(nome) - 1;
	char* lastName = ultimoNome(nome);
	int tamanhoLastName = strlen(lastName);
	int tamanhoFor = strlen(nome) - tamanhoLastName;
	char iniciais[100];
	iniciais[0] = ',';
	iniciais[1] = nome[0];
	iniciais[2] = '.';
	int j = 3;
	for (int i = 0; i < tamanhoFor; i++) {
		if (nome[i] == ' ') {
			iniciais[j] = nome[i + 1];
			j++;
			iniciais[j] = '.';
			j++;
			brancos -= 1;
		}
		if(brancos == 0)break;
	}
	iniciais[j] = 0;
	int tamanhoIniciais = strlen(iniciais);
	char* nomeMontado = (char*)malloc(sizeof(char) * (tamanhoIniciais + tamanhoLastName + 1));
	if (nomeMontado == NULL) {
		printf("Erro memória");
		exit(1);
	}
	nomeMontado = strcpy(nomeMontado, lastName);
	nomeMontado = strcat(nomeMontado, iniciais);
	return nomeMontado;
}

char** leNomes(char* nomeDoArquivo, int* nElementos) {
	FILE* finput = fopen(nomeDoArquivo, "r");
	if(finput == NULL){
		printf("Erro de abertura do arquivo");
		exit(2);
	}
	fscanf(finput, "%d", nElementos);
	char** nomes = (char**)malloc(sizeof(char*) * *nElementos);
	if (nomes == NULL) {
		printf("Erro memória");
		exit(1);
	}
	for (int i = 0; i < *nElementos; i++) {
		char nome[50];
		char profissao[50];
		char nacao[50];
		int j = fscanf(finput, " %[^:]: %[^,], %[^\n] ", profissao, nome, nacao);
		if(j == 0){
			printf("erro de leitura do arquivo");
			exit(3);
		}
		nomes[i] = montaNome(nome);
	}
	return nomes;
}

void gravaNomes(char* nomeDoArquivo , char** nomes, int numeroElementos) {
	FILE* foutput = fopen(nomeDoArquivo, "wb");
	if (foutput == NULL) {
		printf("Erro na hora de abrir o arquivo");
		exit(2);
	}

	for (int i = 0; i < numeroElementos; i++) {
		int tamanho = strlen(nomes[i]);
		fwrite(&tamanho, sizeof(int), 1, foutput);
		fwrite(nomes[i], sizeof(char), tamanho, foutput);
	}
	fclose(foutput);
}

void liberaVetor(char** vetorLiberar, int nElementos) {
	for (int i = 0; i < nElementos; i++) {
		free(vetorLiberar[i]);
	}
	free(vetorLiberar);
}


//*** .c ***//

//NOME: MARCOS VIEIRA
//TURMA: 33A  PROFESSOR: WALDEMAR CELES

#define _CRT_SECURE_NO_DEPRECATE
#include "utilidades.h"
#include <stdio.h>

int main(void) {
	char s[] = "John von Neumann";
	
	int brancos = numBrancos(s);
	printf("%d\n", brancos);
	char* nomeNovo = montaNome(s);
	printf("%s\n", nomeNovo);
	
	int nElementos;
	char** nomes = leNomes("P:/pessoas.txt", &nElementos);
	printf("Teste LE NOMES\n");
	for (int i = 0; i < nElementos; i++) {
		printf("Nomes: %s\n", nomes[i]);
	}

	gravaNomes("pessoas.dat", nomes, nElementos);

	liberaVetor(nomes, nElementos);

	printf("TESTE ARQUIVO BINARIO\n");
	FILE* foutputNovo = fopen("pessoas.dat", "rb");
	for (int i = 0; i < nElementos; i++) {
		int tamanho;
		char nome[50];
		fread(&tamanho, sizeof(int), 1, foutputNovo);
		fread(nome, sizeof(char), tamanho, foutputNovo);
        nome[tamanho] = 0;
		printf("NOME: %s  TAMANHO: %d\n", nome, tamanho);
	}
	fclose(foutputNovo);
	return 0;
}
