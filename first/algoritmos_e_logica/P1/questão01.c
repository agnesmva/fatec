/*Elabore um programa em C que leia a hora de início (HI) e a hora do término (HF) de um jogo de xadrez. Considere apenas horas cheias. Sabendo que a uma partida nunca excede 24 horas, e que a partida pode começar um dia e terminar no outro, calcule e determine o tempo de duração da partida. Veja alguns exemplos:
HI == 10 e HF == 18 --> duração da partida 8 horas
HI == 20 e HF == 6 --> duração da partida 10 horas*/
#include <stdio.h>
int main(){
    int HI, HF, duracao, dia;
    printf("Digite o horário incial da partida de Xadrez: ");
    scanf("%d", & HI);
    printf("Digite o horário final da partida de Xadrez: ");
    scanf("%d", & HF);
    if (HI <= HF)
    {
    
        
        duracao = (HF - HI);
    }
    else
    {

        duracao = (24 - HI) + HF;
    }
    printf("O horário de duração da prova de xadrez é de:  %d horas", duracao);
    return 0;
}