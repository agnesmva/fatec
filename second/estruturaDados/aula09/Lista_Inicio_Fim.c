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
    p->info = *val;
    free(p);
}
void Rem_Fim(NO **Inicio, NO **Fim, int **val){
    NO *p, *q;
    p = *Fim;
    if (*Inicio == *Fim){
        *Inicio = NULL;
        *Fim = NULL;
    }
    else{
        q = *Inicio;
        while (q->prox != *Fim)
            {
                q = q ->prox;
            }
    }
    q->prox = NULL;
    *Fim = q;
    *val = p->info;
    free(p);
    
}
void Transferir_Inicio(NO **Inicio, NO **Fim, NO *r){
    NO *p;
    p = *Inicio;
    while(p->prox != r){
        p = p->prox;
        p->prox = r->prox;
        r->prox = *Inicio;
        *Inicio = r;
        if (r == *Fim){
            *Fim = p;
        }
        break;
        
    }
}
void Transferir_Fim(NO **Inicio, NO **Fim, NO *r){
    NO *p;
    p = *Inicio;
    while(p->prox != r){
        p = p->prox;
        p->prox = r->prox;
        r->prox = *Fim;
        *Fim = r;
        if (r == *Inicio){
            *Inicio = p;
        }
        else{
            r->prox = NULL;
        }
        break;
        
    }
}

NO* Consultar(NO *Inicio, int val){
    NO *p;
    p = Inicio;
    while (p->info != val && p !=NULL)
    {
        p= p->prox;
    }
    return p;
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
	NO *Inicio = NULL, *Fim = NULL, *r;
	int op, val;
	
	do
	{
		
		printf("\n1 - Inserir no Inicio");
		printf("\n2 - Inserir no Fim");
		printf("\n3 - Imprimir a Lista");
        printf("\n4 - Remover no Inicio");
        printf("\n5 - Remover no Fim");
		printf("\n6 - Consultar inteiro");
        printf("\n7 - Transferir NO para o inicio");
        printf("\n8 - Transferir NO para o fim");
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
         case 5:
            if (Inicio == NULL){
                printf("\nLista vazia");
            }
            else{
                Rem_Fim(&Inicio, &Fim, &val);
                printf("\nValor Removido: %d\n",val);
            }
            break;
       case 6:
            printf("Digite o valor a ser consultado: ");
            scanf("%d", &val);
            r = Consultar(Inicio, val);
            if (r == NULL) {
                printf("\nO valor não existe na lista");
            } else {
                printf("Valor encontrado: %d", r->info);
            }
            break;
        case 7:
            printf("Digite o valor para transferir: ");
            scanf("%d", &val);
            r = Consultar(Inicio, val);
            if (r == NULL) {
                printf("\nO valor não existe na lista");
            } else if (r == Inicio) {
                printf("O valor já é o início");
            } else {
                Transferir_Inicio(&Inicio, &Fim, r);
                printf("Valor transferido para o início da lista\n");
            }
            break;
        case 8:
            printf("Digite o valor para transferir: ");
            scanf("%d", &val);
            r = Consultar(Inicio, val);
            if (r == NULL) {
                printf("\nO valor não existe na lista");
            } else if (r == Fim) {
                printf("O valor já é o último");
            } else {
                Transferir_Fim(&Inicio, &Fim, r);
                printf("Valor transferido para o fim da lista\n");
            }
            break;
        

        }
		
		
	}while (op!=0);
return 0;
}
