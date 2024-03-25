#include <stdio.h>_
int main()
{
    int pessoa = 0, idade;
    float media, totalidade = 0;
    do
    {
        pessoa++;
        printf("Digite a idade da pessoa %d: ", pessoa);
        scanf("%d", & idade);
        totalidade += idade;
        
    } while (idade!=0);
    media = totalidade/(pessoa-1); //precisa subtrair pq o do é executado antes de mostrar o print
    printf("Digite a média das pessoas é de %.2f\n", media);
    return 0;
}
