#include <stdlib.h>
#include <stdio.h>

typedef struct pessoa Pessoa;
struct pessoa {
char nome[81];
int dia, mes, ano;
};

int cmp(Pessoa* p1, int ano, int mes, int dia);
Pessoa* buscaOtario(Pessoa** pessoas, int anoB, int mesB, int diaB, int nPessoas);


int main(void) {
    Pessoa p1 = { "Vieira", 4,12,2004 };
    Pessoa p2 = { "Zibordi", 9, 2, 2004 };
    Pessoa p3 = { "Rita", 20, 6, 1971 };
    Pessoa p4 = { "Ciro", 30, 3, 1974 };
    Pessoa p5 = { "Pedro2", 15, 11, 1885};
    Pessoa p6 = { "Thori", 12, 9, 2019};
    Pessoa* ps[6] = {&p5, &p3, &p4, &p2, &p1, &p6 };
    Pessoa* pEpico = buscaOtario(ps, 1972, 6, 20, 6);
    int test = cmp(&p1, 2004, 12, 4);
    printf("%s", pEpico->nome);
    }

    int cmp(Pessoa* p1, int ano, int mes, int dia) {

    if (p1->ano < ano) return 1;
    else if (p1->ano > ano) return 2;
    else {
        if (p1->mes < mes) return 1;
        else if (p1->mes > mes) return 2;
        else {
            if (p1->dia > dia) return 2;
            else if (p1->dia < dia) return 1;
            else return 0;
        }
    }
}

    Pessoa* buscaOtario(Pessoa** pessoas, int anoB, int mesB, int diaB, int nPessoas) {
    int start = 0;
    int end = nPessoas - 1;
    while (start <= end) {
        int mid = (end + start) / 2;
        int resultComp = cmp(pessoas[mid], anoB, mesB, diaB);
        if (resultComp == 1) {
            start = mid + 1;
        }
        else if (resultComp == 2) {
            end = mid - 1;
        }
        else return pessoas[mid];
    }
    return NULL;
}