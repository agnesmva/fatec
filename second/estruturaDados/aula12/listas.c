#include <stdio.h>
#include <stdlib.h>


#define tam 10

void iniciaFila(int *inicio, int *fim){
    *inicio = 0;
    *fim = 0;
}
int inserirFila(int *fila, int *inicio, int *fim, int *val){
    if ((*fim + 1) % tam == *inicio){   
        printf("Fila Cheia\n");
        return 0; 
    }
    else{
        *fim = (*fim+1)%tam;
        printf("%d\n", val);
        fila[*inicio] = val;
        printf("Valor inserido com sucesso %d\n", *val);
        return 1;
    }
    
}
int removeDaFila(int *fila, int *inicio, int *fim, int *val){
    if (*inicio == *fim){
        printf("Fila vazia! Não temos nada a remover\n");
        return 0;
    }
    else{
        *inicio = (*inicio+1)%tam;
        fila[*(fim)] = val;
        printf("Valor removido com sucesso\n");
        return 1;
    }
    
}
void imprimirFila(int *fila, int inicio, int fim){
    int i;
    i = inicio;
    do
    {
        i = (i+1)%tam;
        printf("%d\n", fila[i]);
    } while (i != fim);
    
}

void esperar(){
    printf("Pressione Enter para continuar...");
                getchar(); // Captura o Enter residual
                getchar(); // Aguarda Enter do usuário
}


int main(){
    int fila[tam], inicio, fim, val, op;

    iniciaFila(&inicio, &fim);
    do
    {
        printf("1 - Inserir na fila\n");
        printf("2 - Remover da fila\n");
        printf("3 - Imprimir\n");
        printf("0 - Encerrar o programa\n");
        
        printf("Digite uma opção: ");
        scanf("%d", &op);

         switch (op)
                {
                case 1:
                    printf("\nDigite o valor a ser inserido: ");
                    scanf("%d", &val);
                    inserirFila(fila, &inicio, &fim, &val);
                    break;
                case 2:
                    removeDaFila(fila, &inicio, &fim, &val);
                    break;
                case 3:
                    imprimirFila(fila, fim, inicio);
                    break;
                default:
                    break;
                }
    } while (op != 0);
    
   
    return 0;
}
