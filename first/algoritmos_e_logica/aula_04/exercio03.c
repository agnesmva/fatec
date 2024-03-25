#include <stdio.h>
int main()
{
    int aluno = 1, ap, rp;
    float n1, n2, medal, mediatotal;

      while (aluno <= 5) {
        printf("Digite a primeira nota do aluno %d: ", aluno);
        scanf("%f", &n1);
        printf("Digite a segunda nota do aluno %d: ", aluno);
        scanf("%f", &n2);

        medal = (n1+n2) / 2;
        mediatotal += medal / 5;

        printf("A media do aluno %d e igual a %.2f \n", aluno, medal);
        
        if (medal>=6)
        {
            printf("O aluno %d foi aprovado \n", aluno);
			      ap += 1;
        }
        else
        {
            printf("O aluno %d foi reprovado \n", aluno);
			      rp += 1;
        }
         aluno++;
        printf(" \n --------------------------------------- \n ");
       
      }
      printf("\n A media geral da turma foi de %.2f. \n A quantidade de alunos aprovados foi de %d. \n A quantidade de alunos reprovados foi de %d.", mediatotal, ap, rp);
      
    return 0;
}