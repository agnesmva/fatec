#include <stdio.h>
#include <stdlib.h>

struct dados
{
	int info;
	struct dados *prox;
};

typedef struct dados NO;

void esperar(){
    printf("Pressione Enter para continuar...");
                getchar(); // Captura o Enter residual
                getchar(); // Aguarda Enter do usuário
}


void Ins_Inicio(NO **Inicio, NO **Fim, int val)
{
	NO *p;
	
	p = (NO *)calloc(1,sizeof(NO));
	p->info = val;
	p->prox = *Inicio;
	
	if (*Fim==NULL)
	    *Fim = p;
	    
	*Inicio = p;
}

void Ins_Fim(NO **Inicio, NO **Fim, int val)
{
	NO *p;
	
	p = (NO *)calloc(1,sizeof(NO));
	p->info = val;
	p->prox = NULL;
	
	if (*Inicio==NULL)
	    *Inicio = p;
	else
	    (*Fim)->prox = p;
		
	*Fim = p;	    
}







void Imprime(NO *Inicio)
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

void Rem_Inicio(NO **Inicio, NO **Fim, int *val)
{
	NO *p;
	
	p = *Inicio;
	
	//verificando se só existe um nó 
	if (*Inicio==*Fim)
	{
		*Inicio = NULL;
		*Fim = NULL;
	}
	else
	    *Inicio = p->prox;
	    
	*val = p->info;
	free(p);	
}
void Remover_Duplicados(NO **Inicio, NO **Fim, int val)
{
    NO *p = *Inicio;
    NO *anterior = NULL;
    while (p != NULL)
    {
        if (p->info == val)
        {
            if (p == *Inicio) // Se for o primeiro nó
            {
                Rem_Inicio(Inicio, Fim, &val); 
                p = *Inicio; // Atualiza o ponteiro para o novo início
            }
            else if (p == *Fim) // Se for o último nó
            {
                Rem_Fim(Inicio, Fim, &val);
                p = NULL; // Último nó removido, fim da lista
            }
            else // Nó intermediário
            {
                anterior->prox = p->prox; // Junta anterior com o próximo
                NO *temp = p;
                p = p->prox; // Avança para o próximo nó
                free(temp); // Libera a memória do nó removido
            }
        }
        else
        {
            anterior = p;
            p = p->prox; // Avança para o próximo nó
        }
    }
}
void Rem_Fim(NO **Inicio, NO **Fim, int *val)
{
	NO *p, *q;
	
	p = *Fim;
	//verificando se só existe um nó
	if (*Inicio==*Fim)
	{
		*Inicio = NULL;
		*Fim = NULL;
	}
	else
	{
		q = *Inicio;
		//posicionando q no penultimo nó
		while (q->prox != *Fim)
		    q = q->prox;
		    
		q->prox = NULL;
		*Fim = q;		
	}
	
	*val = p->info;
	free(p);
}


NO * Consultar(NO *Inicio, int val)
{
	NO *p;
	p = Inicio;
	while (p!=NULL && p->info != val)
	   p = p->prox;
	   
	return p;
	
}
void Trans_Inicio(NO **Inicio, NO **Fim, NO *r)
{
	NO *q;
	//q deve estar no NO antes de r
	q = *Inicio;
	while (q->prox != r)
	    q = q->prox;
	    
	q->prox = r->prox;
	r->prox = *Inicio;
	*Inicio = r;
	if (r==*Fim)
	     *Fim = q;
}


void Trans_Fim(NO **Inicio, NO **Fim, NO *r)
{
	NO *q;
	
	if (r==*Inicio)
	    *Inicio = r->prox; //colocando Inicio no 2o. nó
	else
	{
		q = *Inicio;
		while(q->prox != r)
		    q = q->prox;
			
		q->prox = r->prox;	
	}		
	r->prox = NULL;
	(*Fim)->prox = r;
	*Fim = r;
}



main()
{
	NO *Inicio, *Fim, *r;
	int op, val;
	
	//criando a lista vazia...
	Inicio = NULL;
	Fim = NULL;
	
	do
	{
		system("cls");
		printf("\n1 - Inserir no Inicio");
		printf("\n2 - Inserir no Fim");
		printf("\n3 - Imprimir a Lista");
		printf("\n4 - Remover no Inicio");
		printf("\n5 - Remover no Fim");
		printf("\n6 - Consultar Valor");
		printf("\n7 - Transferir NO para o Inicio");
		printf("\n8 - Transferir NO para o Fim");
		
		
		printf("\n9 - Remover ocorrencias repetidas");
		
				
		printf("\n0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Inicio(&Inicio, &Fim, val);
			        break;
			        
			case 2: printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Fim(&Inicio, &Fim, val);
					break;
			
			case 3: if (Inicio==NULL)
			            printf("\nLista Vazia!");
			        else
			        {
			        	printf("\nLista:\n");
			        	Imprime(Inicio);
					}
					esperar();
					break;
					
			case 4: if (Inicio==NULL)
			            printf("\nLista Vazia!");
			        else
			        {
			        	Rem_Inicio(&Inicio, &Fim, &val);
			        	printf("\nValor removido: %d\n", val);
			        }
			        esperar();
			        break;
			        
			case 5: if (Inicio==NULL)
			            printf("\nLista Vazia!");
			        else
			        {
			        	Rem_Fim(&Inicio, &Fim, &val);
			        	printf("\nValor removido: %d\n", val);
			        }
			        esperar();
			        break;
			        
			case 6: printf("\nDigite o valor a procurar:");
			        scanf("%d",&val);
			        
					r = Consultar(Inicio, val);
			        
			        if (r==NULL)
			            printf("\nValor nao existe na lista!\n");
			        else
			            printf("\nValor encontrado:  %d\n", r->info);
			            
			        esperar();
			        break;
			        
			case 7: printf("\nDigite o valor a transferir: ");
			        scanf("%d",&val);
			        
					r = Consultar(Inicio, val);
			        
			        if (r==NULL)
			            printf("\nValor nao existe na lista!\n");
			        else
			            if  (r==Inicio)
			            	printf("\nEste valor ja eh o primeiro!\n");
			            else
			                Trans_Inicio(&Inicio, &Fim, r);
			                
			        esperar();
			        break;
			        
			case 8: printf("\nDigite o valor a transferir: ");
			        scanf("%d",&val);
			        
					r = Consultar(Inicio, val);
			        
			        if (r==NULL)
			            printf("\nValor nao existe na lista!\n");
			        else
			            if (r==Fim)
			            	printf("\nEste No ja eh o ultimo!\n");
			            else
			                Trans_Fim(&Inicio, &Fim, r);
			                
			        esperar();
			        break;
			case 9:printf("\nDigite o valor a ser removido: ");
				   scanf("%d", &val);
				   r = Consultar(Inicio, val);
				   Remover_Duplicados(&Inicio, &Fim, val);
    			   printf("\nTodos os valores %d foram removidos!\n", val);
                   esperar();
    			   break;

			        
			        
			        
			        
			        
			        
			        
			        
			        
			        
			        
			        
		}	
		
	}while (op!=0);
}
