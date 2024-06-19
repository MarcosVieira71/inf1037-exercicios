#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int info;
    Node* prox;
};

void imprime_revrec(Node* l) {
	if (l != NULL) {
		imprime_revrec(l->prox);
		printf("%d\n", l->info);
	}
	else return;
}

Node* insere_ord_rec(Node* l, int info) {
	if (l == NULL || l->info > info) {
		Node* p = (Node*)malloc(sizeof(Node));
		if (p == NULL)
			exit(1);

		p->info = info;
		p->prox = l;

		return p;
	}
	else {
		l->prox = insere_ord_rec(l->prox, info);
		return l;
	}
}