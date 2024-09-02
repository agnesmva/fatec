#include <stdio.h>
#include <stdlib.h>

struct dados
{
	int info;
	struct dados *prox;
};

typedef struct dados NO;

void Ins_Inicio(NO **Inicio, NO **Fim, int val){
    NO *p;
    p = malloc(sizeof(NO)); //casting, converte temporariamente
    p -> info = val;
    p -> prox = *Inicio;
    if(*Fim == NULL){
        *Fim = p;
    }
    *Inicio = p;
}
void Ins_Fim(NO **Inicio, NO **Fim, int val){
    NO *p;
    p = malloc(sizeof(NO));
    p->info = val;
    p->prox = NULL;
    if (*Inicio == NULL){
        *Inicio = p;
    }
    else{
        (*Fim)->prox = p;
        *Fim = p;
    }
    
}
void Rem_Inicio(NO **Inicio, NO **Fim, int **val){
    NO *p;
    p = *Inicio;
    if (*Inicio == *Fim){
        *Inicio = NULL;
        *Fim = NULL;
        
    }
    else{
        *Inicio = p->prox;
        
    }
    free(p);
}

void Imprime(NO *Inicio){
    NO *p;
    p = Inicio;
    while(p != NULL){
        printf("%d -->", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}

int main()
{
	NO *Inicio = NULL, *Fim = NULL;
	int op, val;
	
	do
	{
		
		printf("\n1 - Inserir no Inicio");
		printf("\n2 - Inserir no Fim");
		printf("\n3 - Imprimir a Lista");
        printf("\n4 - Remover no Inicio");
        printf("\n5 - Remover no Fim");
		
		printf("\n0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch (op)
        {
        case 1:
            printf("Digite o valor para inserir no INICIO da lista: ");
            scanf("%d", &val);
            Ins_Inicio(&Inicio, &Fim, val);
            break;
        
        case 2:
            printf("Digite o valor para inserir no FIM da lista: ");
            scanf("%d", &val);
            Ins_Fim(&Inicio, &Fim, val);
            break;

        case 3:
            if (Inicio==NULL){
                printf("\nLista Vazia");
                break;
            }
            else{
                printf("\nLista:\n");
                Imprime(Inicio);
                break;
            }
        case 4:
            if (Inicio == NULL){
                printf("\nLista vazia");
            }
            else{
                Rem_Inicio(&Inicio, &Fim, &val);
                printf("\nValor Removido: %d\n",val);
            }
            break;
        }
		
		
	}while (op!=0);
return 0;
}
