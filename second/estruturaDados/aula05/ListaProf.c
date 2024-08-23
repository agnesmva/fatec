#include <stdio.h>
#include <stdlib.h>

struct dados
{
	int info;
	struct dados *prox;
};

typedef struct dados NO;



void Ins_Inicio (NO **Inicio, int val)
{
	NO *p;
	
	p = (NO *)calloc(1,sizeof(NO));
	p->info = val;
	p->prox = *Inicio;
	*Inicio = p;

}

void Imprime (NO *Inicio)
{
	NO *p;
	
	p = Inicio;
	while (p != NULL)
	{
		printf("%d-->", p->info);
		p = p->prox;
	}
	printf("NULL\n");
}


main()
{
	NO *Inicio;
	int op, val;
	
	Inicio = NULL; //  criando a lista vazia
	
	do
	{
		system("cls");
		printf("\n1 - Inserir no Inicio");
		printf("\n2 - Imprimir a Lista");
		printf("\n3 - Inserir no Fim");
		printf("\n0 - Sair do Programa");
		
		printf("\n\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Inicio(&Inicio , val);
			        break;
			        
			case 2: if (Inicio==NULL)
						printf("\nLista Vazia!");
					else
					{
						printf("\nLista:\n");
						Imprime(Inicio);
						
					}
					system("pause");
					break;
			
			case 3: printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        //Ins_Fim(&Inicio , val);
			        break;
			        
		}
		
	}while (op != 0);	
}

