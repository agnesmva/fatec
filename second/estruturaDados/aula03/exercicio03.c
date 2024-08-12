/*
 Elabore um algoritmo que crie uma função capaz de receber um
parâmetro inteiro. Retorne, em outros dois parâmetros com o sucessor
e o antecessor do número recebido. Crie a função principal e faça a
devida chamada com os parâmetros. Mostre os resultados.
*/
#include <stdio.h>
int SucessoAntecessor(int n, int *a){
    int s;
    s = n+1;
    (*a) = n-1;
    return s;
}
int main()
{
    int a = 10, memoria, c;
    c = SucessoAntecessor(a, &memoria);
    printf("Sucessor %d e o Antecessor é %d\n", c, memoria);
    return 0;
}