#include <stdio.h>
#include <stdlib.h>

struct no_arvore
{
    struct no_arvore *esq;
    int info;
    struct no_arvore *dir;
    
};
typedef struct no_arvore NO;

NO * CAPB(int n){
    NO *r;/* code */
    if(n == 0){
        r = NULL;
    }else{

        r = calloc(1, sizeof(NO));
        printf("Digite o valor a ser inserido: ");
        scanf("%d", r ->info);
        r->esq = CAPB(n/2);
        r->dir = CAPB(n - n/2 - 1);
    }
    return r;
}

int main(int argc, char const *argv[])
{
    NO *Raiz;
    int op, n;
    do
    {
        printf("\n")
        printf("\nDigite a opção:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite a quantidade de nós que esta arvore possui: ");
            scanf("%d", &n);
            break;
        
        default:
            break;
        }
        
    } while (op!=0);
    
    return 0;
}

