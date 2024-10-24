#include <stdio.h>
#include <stdlib.h>

struct no_arvore
{
    struct no_arvore *esq;
    int info;
    struct no_arvore *dir;
    
};
typedef struct no_arvore NO;

void pre_order(NO *Raiz){
    if(Raiz != NULL){
        printf("%d ", Raiz->info);
        pre_order(Raiz->esq);
        pre_order(Raiz->dir);
    }
}

void in_order(NO *Raiz){
    if(Raiz != NULL){
        in_order(Raiz->esq);
        printf("%d ", Raiz->info);
        in_order(Raiz->dir);
    }
}

void pos_order(NO *Raiz){
    if(Raiz != NULL){
        pos_order(Raiz->esq);
        pos_order(Raiz->dir);
        printf("%d ", Raiz->info);
    }
}

int tam_arvore(NO *Raiz) {
    int tam = 0;
    if (Raiz == NULL) {
        return tam;
    } else {
        while (Raiz->esq != NULL)
        {
            Raiz = Raiz->esq;
            tam++;
        }
        
    }
    return tam;
}

NO * CAPB(int n){
    NO *r;
    if(n == 0){
        r = NULL;
    }else{
        r = calloc(1, sizeof(NO));
        if (r == NULL) {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &(r->info));
        r->esq = CAPB(n/2);
        r->dir = CAPB(n - n/2 - 1);
    }
    return r;
}

int main()
{
    NO *Raiz = NULL; // Inicializando a árvore como vazia
    int op, n, alt;

    do {
        printf("\nDigite 1 - Inserir a arvore");
        printf("\nDigite 2 - Imprimir a arvore");
        printf("\nDigite 3 - Calcular a altura da arvore");
        printf("\nDigite 0 - Sair");
        printf("\nDigite a opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite a quantidade de nós que esta arvore possui: ");
            scanf("%d", &n);
            Raiz = CAPB(n);
            break;

        case 2: 
            if (Raiz == NULL){
                printf("\nRaiz Vazia\n");
            } else {
                printf("\nPreOrder: ");
                pre_order(Raiz);
                printf("\nInOrder: ");
                in_order(Raiz);
                printf("\nPosOrder: ");
                pos_order(Raiz);
                printf("\n");
            }
            break;

        case 3:
            if (Raiz == NULL) {
                printf("\nA arvore está vazia.\n");
            } else {
                alt = tam_arvore(Raiz);
                printf("A altura da arvore é: %d\n", alt);
            }
            break;

        default:
            if (op != 0) {
                printf("Opção inválida!\n");
            }
            break;
        }

    } while (op != 0);

    return 0;
}
