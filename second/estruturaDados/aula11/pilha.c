#include <stdio.h>
#include <stdlib.h>

define tam 10 //constante chamada tam

typedef struct {
    int top;
    int info[tam];
}PILHA;

/*
struct dados{
    int top;
    int info[tam];
};

typedef struc dados PILHA;
*/

void Inicilaiza(PILHA *p){
    p->topo = -1;
}

int main(){

    PILHA S;
    int op, val;

    Inicializa(&S);

    return 0;
}
