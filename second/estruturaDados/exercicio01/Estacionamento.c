#include <stdio.h>
#include <stdlib.h>

#define tam 10
struct  dados
{
    int topo;
    char carro[tam];
};
typedef struct dados PILHA;

void esperar(){
    printf("Pressione Enter para continuar...");
                getchar(); // Captura o Enter residual
                getchar(); // Aguarda Enter do usuário
}

void  Inicializa(PILHA *p)
{
	p->topo = -1; 
}

int Cheia (PILHA *p)
{
	return p->topo==tam-1;
}

int Vazia(PILHA *p)
{
	return p->topo==-1;
}

int  Push(PILHA *p, char l)
{
	if (Cheia(p)){
        return 0;
    }
	p->carro[++p->topo] = l;
	return 1;
}

int Pop(PILHA *p, PILHA *q, char *l)
{
    if (Vazia(p)) {
        return 0; // Pilha vazia
    }

    char removido;
    int encontrado = 0;

    while (!Vazia(p) && !encontrado) {
        removido = p->carro[p->topo--];
        
        if (removido == *l) {
            encontrado = 1;
        } else {
            Push(q, removido);
        }
    }
    
    // Após remover, devolvemos os carros da auxiliar para a pilha principal
    while (!Vazia(q)) {
        removido = q->carro[q->topo--];
        Push(p, removido);
    }
    return encontrado;
}


void Imprime (PILHA p)
{
	int i;
	for (i=p.topo; i>=0; i--)
	    printf("[%c]\n", p.carro[i]);
}

int main(){
    PILHA Principal, Aux;
    int opcao;
    char letra;
    Inicializa(&Principal);
    Inicializa(&Aux);

    do{
    
        printf("1 - Vamos inserir um carro no estacionamento\n");
        printf("2 - Vamos remover um carro do estacionamento\n");
        printf("3 - Me mostre os carros na pilha\n");
        printf("4 - Vamos inserir carros aleatórios\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite a letra do carro para ser inserido\n");
            scanf(" %c", &letra);
            if (Push(&Principal, letra) == 0){
                printf("Pilha Cheia!\n Não foi possível inserir mais nenhum carro.\n");
            }
            else{
                printf("Carro adicionado com sucesso!\n");
            }
            esperar();
            break;
        case 2:
            printf("Digite a letra do carro para ser removido");
            scanf(" %c", &letra);
            if(Pop(&Principal, &Aux, &letra) == 0){
                printf("Pilha vazia!\n Nenhum Valor a ser removido\n");
            }
            else{
                printf("Valor removido com sucesso \n O carro removido foi %c", letra);
            }
            esperar();
            break;
        case 3:
            if(Vazia(&Principal)){
                printf("Pilha vazia\n Não é possível remover nenhum valor");
            }
            else{
                printf("\nCarros Estacionados\n");
                Imprime(Principal);
            }
            esperar();
            break;
        default:
            printf("Digite um valor válido.");
            break;
        }


    }
    while(opcao != 0);
    return 0;
}


