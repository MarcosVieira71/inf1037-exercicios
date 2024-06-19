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
    return 0;
}

Node* mergeList(Node* l1, Node* l2){
    Node* temp;
    for(; l1 != NULL && l2 != NULL; l1 = l1->next, l2 =l2->next){
        if(l2->id > l1->id){
            temp = l1;
            l1 = l1->next;
        
    }
   }

}

Node* createList(Node* l, int id, char* name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name,name);
    newNode->next = l;
    return newNode;
}

void showList(Node* l){
    for(Node* p = l; p!=NULL; p=p->next) printf("id: %d | name: %s", p->id, p->name);
}

void freeList(Node* l){
    Node* t = l;
    while(t!=NULL){
            Node* q = t->next;
            free(t);
            t =q;
        }
}

