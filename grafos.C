#define SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grafo Grafo;
typedef struct aresta Aresta;
typedef struct node Node;

struct node {
	int i;
	struct node* next;
};

struct aresta {
	int verticeInicial;
	int verticeFinal;
};

struct grafo {
	struct node* vetor[SIZE];
};

Node* insertNode(Node* head, int endNode);
Grafo* createGraph(void);
Grafo* setGraph(Grafo* grafo, Aresta* arestas, int tamanho);
void printGraph(Grafo* grafo);
int isEdge(Grafo* grafo, int verticeInicial, int verticeFinal);
void freeGraph(Grafo* grafo);

int main(void) {
	Aresta conjArestas1[] = {
		{1,2}, {2,0},
		{3,1}, {2,1}, { 4,2 }, {0,1}
	};
	Grafo* grafo = createGraph();
	grafo = setGraph(grafo, conjArestas1, 6);
	printGraph(grafo);
	printf("%d\n", isEdge(grafo, 2, 0));
	printf("%d\n", isEdge(grafo, 2, 4));
	freeGraph(grafo);
	return 0;
}

Grafo* createGraph(void) {
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
	if (grafo == NULL) exit(1);
	for (int i = 0; i < SIZE; i++) {
		grafo->vetor[i] = NULL;
	}
	return grafo;
}
Node* insertNode(Node* head, int endNode) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) exit(1);
	newNode->next = head;
	newNode->i = endNode;
	return newNode;
}

Grafo* setGraph(Grafo* grafo, Aresta* arestas, int tamanho){
	for (int i = 0; i < tamanho; i++) {
		grafo->vetor[arestas[i].verticeInicial] = insertNode(grafo->vetor[arestas[i].verticeInicial], arestas[i].verticeFinal);
	}
	return grafo;
}

void printGraph(Grafo* grafo){
	for (int i = 0; i < SIZE; i++) {
		for (Node* p = grafo->vetor[i]; p != NULL; p = p->next)
			printf("(%d -> %d)\n", i, p->i);
	}
}

int isEdge(Grafo* grafo, int verticeInicial, int verticeFinal) {
	for (int i = 0; i < SIZE; i++) {
		for (Node* p = grafo->vetor[i]; p != NULL; p = p->next)
			if((verticeFinal == p->i) && (verticeInicial == i)) return 1;
	}
	return 0;
}

void freeGraph(Grafo* grafo) {
	for (int i = 0; i < SIZE; i++) {
		Node* t = grafo->vetor[i];
		while (t != NULL) {
			Node* p = t->next;
			free(t);
			t = p;
		}
	}
	free(grafo);
}