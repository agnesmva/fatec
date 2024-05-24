#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
 int M[5][12], semana, mes, maiorProd = 0, maiorProdSemana, maiorProdMes;
 char A[12][15] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
 
 srand(time(NULL));
 
 for (semana = 0; semana < 5; semana++){
  for (mes = 0; mes < 12; mes++){
   M[semana][mes] = rand() % 50;
   M[4][mes] = 0;
   M[semana][11] = 0;
   if (M[semana][mes] > maiorProd){
    maiorProd = M[semana][mes];
    maiorProdSemana = semana;
    maiorProdMes = mes;
   }
  }
 }
 
 for (semana = 0; semana < 4; semana++){
  for (mes = 0; mes < 11; mes++){
   M[4][mes] += M[semana][mes];
   M[semana][11] += M[semana][mes];
   M[4][11] += M[4][mes];
  }
 }
 
 for (semana = 0; semana < 5; semana++){
  printf("| ");
  for (mes = 0; mes < 12; mes++){
   printf("%4d | ", M[semana][mes]);
  }
  printf("\n");
 }
 
 
 printf("\nO mes e a semana de maior producao foram %d e %d, com %d pecas produzidas", maiorProdMes+1, maiorProdSemana+1, maiorProd);
}