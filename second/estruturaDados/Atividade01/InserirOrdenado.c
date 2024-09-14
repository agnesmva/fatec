#include <stdio.h>
#include <stdlib.h>

struct dados
{
	int info;
	struct dados *prox;
};

typedef struct dados NO;

void Pause(){ 
    getchar();
    printf("Pressione Enter para continuar...\n");
    getchar();
    
    
}


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

void Ins_Fim(NO **Inicio, int val)
{
	NO *p, *q;
	
	p = (NO *)calloc(1,sizeof(NO));
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

void Rem_Inicio (NO **Inicio, int *val)
{
	NO *p;
	
	p = *Inicio;
	*Inicio = p->prox;
	*val = p->info;
	free(p);
}

void Rem_Fim(NO **Inicio, int *val)
{
	NO *p, *q;
	
	p = *Inicio;
	if (p->prox==NULL)  // se só existe um nó
		*Inicio = NULL;
	else
	{
		//andar com p e q de modo que p seja o ultimo
		// e q o penultimo
		while (p->prox != NULL)
		{
			q = p;
			p = p->prox;
		}
		q->prox = NULL;
		
	}
	
	*val = p->info;
	free(p);
}


NO * Consultar (NO *Inicio, int val)
{
	NO *p;
	
	p = Inicio;
	while (p != NULL && p->info != val)
		p = p->prox;
		
	return p;
	
}

void Rem_Meio(NO *Inicio, NO *r)
{
	NO *p;
	
	p = Inicio;
	while (p->prox != r)
	   p = p->prox;
	   
	p->prox = r->prox;
	free(r);
}

void Ins_Depois(NO *r, int val)
{
	NO *p;
	
	p = (NO *)calloc(1,sizeof(NO));
	p->info = val;
	p->prox = r->prox;
	r->prox = p;
}


void Ins_Antes(NO *Inicio, NO *r, int val)
{
	NO *p, *q;
	
	p = (NO *)calloc(1,sizeof(NO));
	p->info = val;
	p->prox = r;
	
	q=Inicio;
	while (q->prox != r)
	    q = q->prox;
	    
	q->prox = p;
}
void Ins_Ordenado(NO **Inicio, int val)
{
    NO *p, *q, *novo;
    
    novo = (NO *)malloc(sizeof(NO)); 
    novo->info = val;
    novo->prox = NULL;

    if (*Inicio == NULL || (*Inicio)->info > val)
    {
        novo->prox = *Inicio;
        *Inicio = novo;
    }
    else
    {
        p = *Inicio;
        // Caminha até encontrar o local correto para inserir
        while (p->prox != NULL && p->prox->info < val)
        {
            p = p->prox;
        }
        // Insere o novo nó no local correto
        novo->prox = p->prox;
        p->prox = novo;
    }
}




int main()
{
	NO *Inicio, *r;
	int op, val;
	
	Inicio = NULL; //  criando a lista vazia
	
	do
	{
        system("clear");
		printf("\n1 - Inserir no Inicio");
		printf("\n2 - Imprimir a Lista");
		printf("\n3 - Inserir no Fim");
		printf("\n4 - Remover no Inicio");
		printf("\n5 - Remover no Fim");
		printf("\n6 - Consultar um No");
		printf("\n7 - Remover um No");
		printf("\n8 - Inserir depois de um No");
		printf("\n9 - Inserir antes de um No");
		
		//case 10 --> valerá pontos na P1
		
		printf("\n10 - Inserir de forma Ordenada");
		
		/*
			A lista começara vazia e, cada vez que chamar o case 
			10, o valor a ser inserido deve estar no lugar
			correto, respeitando a ordem crescente.
		
		*/
		printf("\n11 - Zerar lista");
		printf("\n0 - Sair do Programa");
		
		printf("\n\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: 
                    printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Inicio(&Inicio , val);
			        break;
			        
			case 2: 
                    if (Inicio==NULL)
						printf("\nLista Vazia!\n");
					else
					{
						printf("\nLista:\n");
						Imprime(Inicio);
						
					}
					Pause();
					break;
			
			case 3: 
                    printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Fim(&Inicio , val);
			        break;
			        
			case 4: 
                    if (Inicio==NULL)
			   			printf("\nLista Vazia!\n");
			   		else
			   		{
					 	Rem_Inicio(&Inicio, &val);
					 	printf("\nFoi removido: %d\n", val);
					}
			   			
			   		Pause();
			   		break;
			   		
			case 5: 
                    if (Inicio==NULL)
			   			printf("\nLista Vazia!\n");
			   		else
			   		{
					 	Rem_Fim(&Inicio, &val);
					 	printf("\nFoi removido: %d\n", val);
					}
			   			
			   		Pause();
			   		break;
			   		
			case 6: 
                    printf("\nDigite o valor a procurar: ");
					scanf("%d", &val);
					
					r = Consultar(Inicio, val);
					
					if (r==NULL)
						printf("\nValor %d nao existe na lista!\n", val);
					else
						printf("\nValor encontrado: %d\n", r->info);
						
					Pause();
					break;
						
						
			case 7: 
                    printf("\nDigite o valor a remover: ");
					scanf("%d", &val);
					
					r = Consultar(Inicio, val);
					
					if (r==NULL)
						printf("\nValor %d nao existe na lista!\n", val);
					else
					{
						// remover r
						if (r == Inicio) // r é o primeiro
							Rem_Inicio(&Inicio, &val);
						else
							if (r->prox == NULL) //r é o último
								Rem_Fim(&Inicio, &val);
							else
								Rem_Meio(Inicio, r);
						
						printf("\nValor removido com sucesso!\n");
					}
					Pause();
					break;
					
			case 8: 
                    printf("\nDigite o valor a procurar: ");
					scanf("%d", &val);
					
					r = Consultar(Inicio, val);
					
					if (r==NULL)
						printf("\nValor %d nao existe na lista!\n", val);
					else
					{
						printf("\nDigite o valor a inserir:");
						scanf("%d",&val);
						if (r->prox == NULL)
							Ins_Fim(&Inicio, val);
						else
							Ins_Depois(r, val);
				
					}
					Pause();
					break;
					
			case 9: 
                    printf("\nDigite o valor a procurar: ");
					scanf("%d", &val);
					
					r = Consultar(Inicio, val);
					
					if (r==NULL)
						printf("\nValor %d nao existe na lista!\n", val);
					else
					{
						printf("\nDigite o valor a inserir:");
						scanf("%d",&val);
						if (r == Inicio)
							Ins_Inicio(&Inicio, val);
						else
							Ins_Antes(Inicio, r, val);
					}
					Pause();
					break;

            case 10:
                    printf("\nDigite o valor a inserir ordenado:");
                    scanf("%d",&val);
                    Ins_Ordenado(&Inicio, val);
                    break;

            case 11:
                    printf("Limpando a lista...\n");
                    printf("......\n");
                    Pause();
                    Inicio = NULL;
                    break;

									
					
			        
		}
		
	}while (op != 0);

    return 0;	
}
