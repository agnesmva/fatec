#include <stdio.h>
#include <stdlib.h>

struct dados
{
	int info;
	struct dados *prox;
};

typedef struct dados NO;


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
void Ins_Inicio (NO **Inicio, int val)
{
	NO *p;
	
	p = (NO *)malloc(sizeof(NO));
	p->info = val;
	p->prox = *Inicio;
	*Inicio = p;

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
void Ins_Depois(NO *r, int val){
    NO *p;
    p = malloc(sizeof(NO));
    p->info = val;
    p->prox = r->prox;
    r->prox = p;


}
void Ins_Antes(NO *Inicio, NO *r, int val){
    NO *p, *q;
    p = malloc(sizeof(NO));
    p->info = val;
    p->prox = r->prox;

    q = Inicio;
    while (q->prox != r){
        q = q->prox;
    }
    q->prox = p;
    

}
void Subs_No(NO *r, int val){
    NO *p;
    p = r->prox;
    p->info = val;

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

void Rem_meio(NO *Inicio, NO *r){
    NO *p;
    p = Inicio;
       // Caminha até o nó anterior ao que se deseja remover
    while (p != NULL && p->prox != r)
    {
        p = p->prox;
    }
    
    // Se encontramos o nó anterior, removemos o nó r
    if (p != NULL) {
        p->prox = r->prox;
        free(r);
    }
    /*
    Não consegui executar esse algortimo da falha na segmentação da memória
    while (p->prox != r)
    {
        p = p->prox;
        p->prox = r->prox;
        free(r);
    }
    */
    
    
    
}

NO* consultar(NO *Inicio, int val){
    NO *p;
    p = Inicio;
    while (p->info != val && p !=NULL)
    {
        p= p->prox;
    }
    return p;
    
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
        printf("\n7 - Remover um NO");
        printf("\n8 - Inserir depois de um NO");
        printf("\n9 - Inserir antes do NO");
		printf("\n10 - Inserir de Forma Ordenada");
		printf("\n0 - Sair do Programa");
		
		printf("\n\nDigite a opcao: ");
		scanf("%d", &op);

        /*
        Fazer case 10 
        Inserir de forma ordenada 
        A lista comecerá vazia e, cada vez que chamar o case 10, o valor a ser inserido deve estar no lugar correto, respeitando a ordem crescente.
        */
		
		switch(op)
		{
			case 1: printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Inicio(&Inicio , val);
			        break;
			        
			case 2: if (Inicio==NULL){
						printf("\nLista Vazia!\n");
					}
					else{
						printf("\nLista:\n");
						Imprime(Inicio);
					}
					printf("Pressione Enter para continuar...");
    				getchar(); 
    				getchar(); 
					
					break;
			
			case 3: printf("\nDigite o valor a inserir:");
			        scanf("%d", &val);
			        Ins_Fim(&Inicio , val);
			        break;
			        
			case 4: if (Inicio==NULL)
			   			printf("\nLista Vazia!\n");
			   		else{
					 	Rem_Inicio(&Inicio, &val);
					 	printf("\nFoi removido: %d\n", val);
					}
			   			
			   		
			   		break;
			   		
			case 5: if (Inicio==NULL)
			   			printf("\nLista Vazia!\n");
			   		else
			   		{
					 	Rem_Fim(&Inicio, &val);
					 	printf("\nFoi removido: %d\n", val);
					}
			   			
			   	
			   		break;
			   		
			case 6: printf("\nDigite o valor a procurar: ");
					scanf("%d", &val);
					
					r = consultar(Inicio, val);
					
					if (r==NULL){
						printf("\nValor %d nao existe na lista!\n", val);
					}	
					else{
						printf("\nValor encontrado: %d\n", r->info);
					}
					printf("Pressione Enter para continuar...");
    				getchar(); 
    				getchar(); 
					break;

            case 7: printf("\nDigite o valor a ser removido: ");
					scanf("%d", &val);
					
					r = consultar(Inicio, val);
					
					if (r==NULL)
						printf("\nValor %d nao existe na lista!\n", val);
					else{
                        if (r == Inicio){
                            Rem_Inicio(&Inicio, &val);
                        }
                        else if(r->prox == NULL){
                            Rem_Fim(&Inicio, &val);
                        }
                        else{
                            Rem_meio(Inicio, r);
                            printf("Valor removido com sucesso!");
                        }  
                    }
					printf("Pressione Enter para continuar...");
    				getchar(); 
    				getchar(); 
                    break;
			
            case 8: printf("\n Inserir depois de um NO");
                    printf("\nDigite o valor a procurar: ");
					scanf("%d", &val);
					
					r = consultar(Inicio, val);
					
					if (r==NULL)
						printf("\nValor %d nao existe na lista!\n", val);
					else{
                        printf("Digite o valor a ser inserido: ");
                        scanf("%d", &val);
                        if(r->prox == NULL){
                            Ins_Fim(&Inicio, val);
                        }
                        else{
                            Ins_Depois(r, val);
                        }
                    }
					printf("Pressione Enter para continuar...");
    				getchar(); 
    				getchar(); 	
					break;
            case 9: printf("\n Inserir antes de um NO");
                    printf("\nDigite o valor a procurar: ");
					scanf("%d", &val);
					
					r = consultar(Inicio, val);
					
					if (r==NULL)
						printf("\nValor %d nao existe na lista!\n", val);
					else{
                        printf("Digite o valor a ser inserido: ");
                        scanf("%d", &val);
                        if(r->prox == Inicio){
                            Ins_Inicio(&Inicio, val);
                        }
                        else{
                            Ins_Antes(Inicio, r, val);
                        }
                    }
					printf("Pressione Enter para continuar...");
    				getchar(); 
    				getchar(); 	
					break;
			case 10: printf("\n Inserindo de maneira ordenada\n");
					 if (Inicio == NULL){
						Ins_Inicio(&Inicio, val);
					 }
					 else{
						
					 }
					 break;
     
		}
		
	}while (op != 0);	

    return 0;
}

