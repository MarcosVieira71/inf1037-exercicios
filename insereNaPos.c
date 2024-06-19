#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int id;
    Node* next;
};

Node* insereNaPosicao(Node* l, int x, int pos);

int main(void){
    Node* l = insereNaPosicao(NULL, 1, 1);
    l = insereNaPosicao(l, 2, 2);
    l = insereNaPosicao(l, 3, 3);
    l = insereNaPosicao(l, 5, 4);
    l = insereNaPosicao(l, 4, 4);
    l = insereNaPosicao(l, 6, 2);
    for(Node* p = l; p!=NULL; p=p->next){
        printf("\n%d\n", p->id);
    }
    return 0;
}


Node* insereNaPosicao(Node* l, int x, int pos){
    Node* current;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = x;
    int i = 1;
    if(i == pos){
        newNode->next = l;
        return newNode;
    }
    for(current = l; current->next != NULL; current= current->next, i++){
        if(i == pos - 1){
            newNode->next = current->next;
            current->next = newNode;
            return l;
        }
    }
    newNode->next = current->next;
    current->next = newNode;
    return l;
}