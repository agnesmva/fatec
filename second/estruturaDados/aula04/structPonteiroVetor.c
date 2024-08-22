#include <stdio.h>
#include <stdlib.h>

 struct dados
    {
        char nome[32];
        int idade;
    };
typedef struct dados PESSOA; //criando um tipo da estrutura de dados

void leitura(PESSOA *v, int tam){
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("Digite o nome: ");
        fflush(stdin);
        scanf("%s",&v[i].nome);
        printf("Digite a idade do usuário: ");
        scanf("%d",&v[i].idade);
    }
    
}
void mostrar(PESSOA *v, int tam){
    int i;
    for (i = 0; i < tam; i++)
    {
       printf("\nNome: %s e a idade: %d\n", v[i].nome, v[i].idade);
    }

}
float media(PESSOA *v, int tam){
    int i;
    float soma=0;
    for (i = 0; i < tam; i++)
    {
        soma+=v[i].idade;
    }
    return soma/tam;
}
int main()
{
    int n;
    float med;
    PESSOA *p;
    printf("\nDigite a quantidade de pessoas que vamos cadastrar: ");
    scanf("%d", &n);
    p = (PESSOA *)calloc(n, sizeof(PESSOA));
    leitura(p,n);
    mostrar(p,n);
    med = media(p,n);
    printf("A media das idades é: %.2f\n", med);
    
   
    return 0;
}
