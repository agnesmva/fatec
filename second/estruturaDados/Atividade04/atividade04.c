#include <stdio.h>
#include <stdlib.h>

struct no_arvore
{
	struct no_arvore *esq;
	int info;
	struct no_arvore *dir;
};

typedef struct no_arvore NO;

void Insere(NO **Raiz, int val)
{
	if (*Raiz == NULL)
	{
		(*Raiz) = (NO *)calloc(1, sizeof(NO));
		(*Raiz)->info = val;
		(*Raiz)->esq = NULL;
		(*Raiz)->dir = NULL;
	}
	else
		if (val < (*Raiz)->info)
			Insere(&(*Raiz)->esq, val);
		else
			Insere(&(*Raiz)->dir, val);
}

NO *Busca_Pai(NO *Raiz, NO *r)
{
	if (Raiz->esq == r || Raiz->dir == r)
		return Raiz;
	else if (r->info < Raiz->info)
		return Busca_Pai(Raiz->esq, r);
	else
		return Busca_Pai(Raiz->dir, r);
}
NO * Busca_SR(NO *Raiz, int val)
{
	NO *p;
	
	p = Raiz;
	while (p != NULL && p->info != val)
	{
		if (val < p->info)
			p = p->esq;
		else
			p = p->dir;
		
	}
	return p;
	
}

void Remover(NO **Raiz, NO *r)
{
	NO *pai, *substituto;

	// Caso 1: Nó é uma folha
	if (r->esq == NULL && r->dir == NULL)
	{
		pai = Busca_Pai(*Raiz, r);
		if (pai != NULL)
		{
			if (pai->esq == r)
				pai->esq = NULL;
			else
				pai->dir = NULL;
		}
		else
		{
			*Raiz = NULL;
		}
		free(r);
	}
	// Caso 2: Nó tem um único filho
	else if (r->esq == NULL || r->dir == NULL)
	{
		substituto = (r->esq != NULL) ? r->esq : r->dir;
		pai = Busca_Pai(*Raiz, r);
		if (pai != NULL)
		{
			if (pai->esq == r)
				pai->esq = substituto;
			else
				pai->dir = substituto;
		}
		else
		{
			*Raiz = substituto;
		}
		free(r);
	}
	// Caso 3: Nó tem dois filhos
	else 
	{
		NO *menor = r->dir;
		NO *pai_menor = r;
		while (menor->esq != NULL)
		{
			pai_menor = menor;
			menor = menor->esq;
		}
		r->info = menor->info; 
		if (pai_menor->esq == menor)
		{
			pai_menor->esq = menor->dir;
		}
		else
		{
			pai_menor->dir = menor->dir;
		}
		free(menor);
	}
}

void Pre_Order(NO *Raiz)
{
	if (Raiz != NULL)
	{
		printf("%d ", Raiz->info);
		Pre_Order(Raiz->esq);
		Pre_Order(Raiz->dir);
	}
}

void In_Order(NO *Raiz)
{
	if (Raiz != NULL)
	{
		In_Order(Raiz->esq);
		printf("%d ", Raiz->info);
		In_Order(Raiz->dir);
	}
}

void Pos_Order(NO *Raiz)
{
	if (Raiz != NULL)
	{
		Pos_Order(Raiz->esq);
		Pos_Order(Raiz->dir);
		printf("%d ", Raiz->info);
	}
}

NO *Busca(NO *Raiz, int val)
{
	if (Raiz == NULL)
		return NULL;
	else if (Raiz->info == val)
		return Raiz;
	else if (val < Raiz->info)
		return Busca(Raiz->esq, val);
	else
		return Busca(Raiz->dir, val);
}

int main()
{
	NO *Raiz, *r, *Pai;
	int op, val, A[10] = {50, 30, 80, 10, 40, 60, 90, 20, 100, 70}, i;

	Raiz = NULL; // Criando árvore vazia

	do
	{
		system("cls");
		printf("\n1 - Inserir Valor");
		printf("\n2 - Percursos");
		printf("\n3 - Buscar um Valor");
		printf("\n4 - Buscar Pai de um Nó");
		printf("\n5 - Buscar valor sem recursão");
        printf("\n6 - Remover um valor");
		printf("\n0 - Sair do Programa");
		printf("\nDigite a opcao: ");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			for (i = 0; i < 10; i++)
			{
				printf("\nInserindo: %d", A[i]);
				Insere(&Raiz, A[i]);
			}
			system("pause");
			break;

		case 2:
			if (Raiz == NULL)
				printf("\nArvore Vazia!");
			else
			{
				printf("\nPRE: ");
				Pre_Order(Raiz);
				printf("\nIN:  ");
				In_Order(Raiz);
				printf("\nPOS: ");
				Pos_Order(Raiz);
				printf("\n");
			}
			system("pause");
			break;

		case 3:
			printf("\nDigite o valor a procurar: ");
			scanf("%d", &val);
			r = Busca(Raiz, val);
			if (r == NULL)
				printf("\nValor nao existe na arvore!\n");
			else
				printf("\nValor encontrado: %d\n", r->info);
			system("pause");
			break;

		case 4:
			printf("\nDigite o valor que deseja saber o Pai: ");
			scanf("%d", &val);
			r = Busca(Raiz, val);
			if (r == NULL)
				printf("\nValor nao existe na arvore!\n");
			else if (r == Raiz)
				printf("\nA Raiz nao possui pai!\n");
			else
			{
				Pai = Busca_Pai(Raiz, r);
				printf("\nO pai de %d = %d\n", r->info, Pai->info);
			}
			system("pause");
			break;
        
        case 5:
        printf("\nDigite o valor que deseja saber o Pai: ");
        scanf("%d", &val);
        if (Raiz==NULL)
            printf("\nArvore Vazia!\n");
        else
        {
            r = Busca(Raiz, val);
            if (r==NULL)
                printf("\nValor nao existe na arvore!\n");
            else
                if (r==Raiz)
                    printf("\n A Raiz nao possui pai!\n");
                else
                {
                    Pai = Busca_Pai(Raiz, r);
                    printf("\nO pai de %d = %d\n", r->info, Pai->info);
                    
                }
        }
        system("pause");
        break;

		case 6:
			printf("\nDigite o valor a remover: ");
			scanf("%d", &val);
			r = Busca(Raiz, val);
			if (r == NULL)
				printf("\nValor nao existe na arvore!\n");
			else
			{
				Remover(&Raiz, r);
				printf("\nValor removido com sucesso!\n");
			}
			system("pause");
			break;
		}
	} while (op != 0);

	return 0;
}
