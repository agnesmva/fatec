#include <stdio.h>
#include <stdlib.h>

struct dados
{
    struct dados *esq;
    int info;
    struct dados *dir;
};

typedef struct dados NO;
void esperar(){
    printf("Pressione Enter para continuar...");
                getchar(); // Captura o Enter residual
                getchar(); // Aguarda Enter do usuário
}

void Ins_inicio(NO **Inicio, NO **Fim, int val) {
    NO *p;
    p = (NO *)calloc(1, sizeof(NO)); // Alocando novo nó
    p->info = val;
    p->esq = NULL; // Será o primeiro nó, então não terá nó à esquerda
    p->dir = *Inicio; // O próximo nó será o antigo início
    
    if (*Inicio == NULL) { // Se a lista estiver vazia
        *Fim = p; // O Fim também aponta para o novo nó
    } else {
        (*Inicio)->esq = p; // O antigo início agora aponta para o novo nó na esquerda
    }
    *Inicio = p; // Atualiza o início
}

void Ins_fim(NO **Inicio, NO **Fim, int val) {
    NO *p;
    p = (NO *)calloc(1, sizeof(NO)); // Alocando novo nó
    p->info = val;
    p->esq = *Fim; // Será o primeiro nó, então não terá nó à esquerda
    p->dir = NULL; // O próximo nó será o antigo início
    
    if (*Inicio == NULL) { // Se a lista estiver vazia
        *Fim = p; // O Fim também aponta para o novo nó
    } else {
        (*Fim)->dir = p; // O antigo início agora aponta para o novo nó na esquerda
    }
    *Fim = p; // Atualiza o início
}
void Imprimir(NO *Inicio) {
    NO *p;
    p = Inicio;
    printf("NULL ");
    while (p != NULL) {
        printf("<- %d -> ", p->info); // Exibindo o valor
        p = p->dir;
    }
    printf("NULL\n");
}
void Rem_inicio(NO **Inicio, NO **Fim, int *val){
    NO *p;
    p=*Inicio;
    if(p == *Fim){
        *Inicio= NULL;
        *Fim = NULL;
        
    }
    else{
        *Inicio = p->dir;
        (*Inicio)->esq = NULL;
    }
    *val = p->info;
    free(p);
}
void Rem_fim(NO **Inicio, NO **Fim, int *val){
    NO *p;
    p=*Fim;
    if(p == *Inicio){
        *Inicio= NULL;
        *Fim = NULL;
        
    }
    else{
        *Fim = p->esq;
        (*Fim)->dir = NULL;
    }
    *val = p->info;
    free(p);
}
NO * consultar(NO *Inicio, int *val){
    NO *p;
    p = Inicio;
    while(Inicio != p){
        
   }
    
}

int main()
{
    NO *Inicio, *Fim, *r;
    int op, val;
    
    // Lista Vazia
    Inicio = NULL;
    Fim = NULL;
    
    do {
        system("clear"); // Limpa a tela (pode mudar para "cls" no Windows)
        printf("\n1 - Inserir no Inicio");
        printf("\n2 - Inserir no Fim");
        printf("\n3 - Imprimir a Lista");
        printf("\n4 - Remover Inicio da Lista");
        printf("\n5 - Remover Fim da Lista");
        printf("\n6 - Consultar Valor");
        printf("\n7 - Remover Valor escolhido");
        printf("\n0 - Sair do programa");
        
        printf("\nDigite a opcao: ");
        scanf("%d", &op);
        
        switch(op) {
            case 1: 
                printf("\nDigite o valor a inserir: ");
                scanf("%d", &val);
                Ins_inicio(&Inicio, &Fim, val); // Chamada da função Ins_inicio
                break;
                
            case 2: 
                printf("\nDigite o valor a inserir: ");
                scanf("%d", &val);
                Ins_fim(&Inicio, &Fim, val);
                break;  
                
            case 3: 
                if (Inicio == NULL)
                    printf("\nLista Vazia!\n");
                else {
                    printf("\nLista:\n");
                    Imprimir(Inicio); // Exibir a lista
                }
                esperar();
                break;
            case 4:
                if(Inicio == NULL){
                    printf("Lista Vazia. Não é possível remover nenhum NÓ");
                }
                else{
                    Rem_inicio(&Inicio, &Fim, &val);
                    printf("Valor removido com sucesso. Foi removido: %d\n", val);
                }
                esperar();
                break;
            case 5:
                if(Inicio == NULL){
                    printf("Lista Vazia. Não é possível remover nenhum NÓ");
                }
                else{
                    Rem_fim(&Inicio, &Fim, &val);
                    printf("Valor removido com sucesso. Foi removido: %d\n", val);
                }
                esperar();
            case 6:
                printf("\nDigite o valor que deseja procurar:");
                scanf("%d", &val);
                r = consultar(Inicio, val);
                if (r==NULL){
                    printf("\nO valor não existe na lista");
                }
                else{
                    printf("\n O valor encontrado: %d", r->info);
                }
                break;
                
        }
        
    } while (op != 0);

    return 0;
}
