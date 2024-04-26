/*
Um número é considerado ASCENDENTE se seus algarismos estão em ordem crescente. Veja alguns números ascendentes: 123, 359, 458, 279, etc. Se você observou bem, a centanea é menor que a dezena é menor que a unidade. Elabore um programa em C que mostre todos os números de 3 algarismos (100 e  999) que são ascendentes.
Dica: quebrar o número em Centena, Dezena e Unidade.
*/
int main() 
{
    int cen, dez, uni;
    printf("Números ascendentes de 3 dígitos:\n");
    for (int i = 100; i <= 999; i++) {
        cen = i / 100;
        dez = (i / 10) % 10;
        uni = i % 10;
        
       
        if (cen < dez && dez < uni) 
        {
            printf("%d\t", i);
        }
    }

    return 0;
}