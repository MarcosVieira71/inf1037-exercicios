#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int id;
    char name[51];
    Node* next;
};

Node* createList(Node* l, int id, char* name);
void showList(Node* l);
void freeList(Node*l);
Node* mergeList(Node* l1, Node* l2);

int main(void){
    Node* l1 = NULL;
    Node* l2 = NULL;
    
    l1 = createList(l1, 777, "rosa");
    l1 = createList(l1, 558, "leo");
    l1 = createList(l1, 333, "rui");
    l1 = createList(l1, 446, "cris");
    l1 = createList(l1, 111, "leo");

    l2 = createList(l2, 888, "lia");
    l2 = createList(l2, 777, "rosa");
    l2 = createList(l2, 554, "vera");
    l2 = createList(l2, 440, "edu");
    l2 = createList(l2, 333, "rui");
    l2 = createList(l2, 111, "leo");

    l1 = mergeList(l1, l2);
    showList(l1);
    return 0;
}

Node* mergeList(Node *lista1, Node *lista2) {
    Node *result = NULL; // Ponteiro para a lista resultante
    Node **lastPtrRef = &result; // Ponteiro para o ponteiro do último nó da lista resultante

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->id < lista2->id) {
            // Adiciona nó de lista1 à lista resultante
            *lastPtrRef = lista1;
            lista1 = lista1->next;
        } else if (lista2->id < lista1->id) {
            // Adiciona nó de lista2 à lista resultante
            *lastPtrRef = lista2;
            lista2 = lista2->next;
        } else {
            // Nós com o mesmo código, adiciona um deles e avança em ambas as listas
            *lastPtrRef = lista1;
            lista1 = lista1->next;
            Node *temp = lista2;
            lista2 = lista2->next;
            free(temp); // Libera o nó duplicado
        }
        lastPtrRef = &((*lastPtrRef)->next); // Avança o ponteiro do último nó
    }

    // Anexa os nós restantes de lista1 ou lista2
    if (lista1 != NULL) {
        *lastPtrRef = lista1;
    } else {
        *lastPtrRef = lista2;
    }

    return result;
}

Node* createList(Node* l, int id, char* name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name,name);
    newNode->next = l;
    return newNode;
}

void showList(Node* l){
    for(Node* p = l; p!=NULL; p=p->next) printf("id: %d | name: %s\n", p->id, p->name);
}

void freeList(Node* l){
    Node* t = l;
    while(t!=NULL){
            Node* q = t->next;
            free(t);
            t =q;
        }
}

