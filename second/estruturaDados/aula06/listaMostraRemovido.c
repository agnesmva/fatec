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
	
	p = (NO *)malloc(sizeof(NO));
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

void Ins_Fim(NO **Inicio, int val)
{
	NO *p, *q;
	
	p = (NO *)malloc(sizeof(NO));
	p->info = val;
	p->prox = NULL;
	
	if (*Inicio == NULL) //se a lista está vazia
	    *Inicio = p;
	else
	{
		q = *Inicio;
		//caminhando com q ate que ele seja o ultimo nó
		while (q->prox != NULL)
		    q = q->prox;
		    
		q->prox = p;		    
	}
}
void Rem_inicio(NO **Inicio, int **val){
    NO *p;

    p = *Inicio;
    *Inicio = p->prox;
    *val = p->info;
    free(p);
}
void Rem_fim(NO **Inicio, int **val){
    NO *p, *q;
    p = *Inicio;
    if (p->prox == NULL){ //caso só exista um Nó
        *Inicio = NULL;
    }
    else{
        while (p->prox !=NULL) //andar com o p e q de modo que p seja o ultimo e q o penultimo
        {
           q = p;
           p = q->prox;    
        }
         q->prox = NULL;
        
    }
    *val = p->info;
    free(p);
    
}

main()
{
	NO *Inicio, *r;
	int op, val;
	
	Inicio = NULL; //  criando a lista vazia
	
	do
	{
		system("cls");
		printf("\n1 - Inserir no Inicio");
		printf("\n2 - Imprimir a Lista");
		printf("\n3 - Inserir no Fim");
        printf("\n4 - Remover no inicio");
        printf("\n5 - Remover último");
		printf("\n0 - Sair do Programa");
		
		printf("\n\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Inicio(&Inicio, val);
			        break;
			        
			case 2: if (Inicio==NULL){
                        printf("\nLista Vazia!");
                        system("pause");
                    }
						
					else{
						printf("\nLista:\n");
						Imprime(Inicio);
						
					}
					system("pause");
					break;
			
			case 3: printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Fim(&Inicio, val);
			        break;
            case 4: 
                if (Inicio == NULL){
                    printf("\nLista Vazia!");
                    system("pause");
                }
                else{
                    Rem_inicio(&Inicio, &val);
                    printf("Removeu o valor %d\n", val);
                }
                break;
            case 5:
                if (Inicio == NULL){
                    printf("\nLista Vazia!");
                    system("pause");
                }
                else{
                    Rem_fim(&Inicio, &val);
                    printf("Removeu o valor %d\n", val);
                }
                break;
            case 6:
                printf("\nDigite o valor a procurar: ");
                scanf("%d", &val);
                r = Consultar(Inicio, val); //não precisa usar & pois não vai precisar mudar o valor, nem mudar nada na memória
                if (r==NULL) {
                    printf("O valor não existe na lista");
                }
                else{
                    printf("Valor encontrado %d", r->info);
                }
                system("pause");
                break;
                
                
                
			        
		}

		
	}while (op != 0);	
}

