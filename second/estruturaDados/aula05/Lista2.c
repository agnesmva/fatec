#include <stdlib.h>

struct dados
{
    int info;
    struct dados *prox;

};

typedef struct dados NO;

void ins_inicio(NO **inicio, int v){

    NO *p;
    p = (NO *)calloc(1, sizeof(NO));
    p -> info = v; 
    p -> prox = *inicio;
    *inicio = p;

    // Coloca os nós como primeiro 
}
void mostralista(NO *inicio){
    NO *p;
    while (inicio != NULL)
    {
        printf("%d\n", p -> info);
        p = p->prox;
    }
    printf("NULL\n");
}
int main()
{
    NO *inicio;
    int op, val;

    inicio = NULL; //CRIANDO A LISTA VAZIA

    do
    {

        
        printf("\nDigite 1 para inserir na lista: ");
        printf("\nDigite 2 para mostrar a lista: ");
        printf("\nDigite 0 sair da lista: ");
        printf("\n\nDigite a opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: 
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &val);
            ins_inicio(&inicio,val); // na frente do parametro só coloca & se a alteração vai ser feita direta na memória, pois ele transporta o endereço de memória.
            break;
        case 2:
            if (inicio==NULL){
                printf("Lista Vazia");
            }
            else{
                printf("Mostrar lista:");
                mostralista(inicio);
            }
            system("pause");
            break;
        }
    } while (op !=0);
    

}