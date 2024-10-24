#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no_arvore {
    struct no_arvore *esq;
    int info;
    struct no_arvore *dir;
};
typedef struct no_arvore NO;

void esperar(){
    printf("Pressione Enter para continuar...");
    getchar(); // Captura o Enter residual
    getchar(); // Aguarda Enter do usuário
}

int randomizar(){
    return rand() % 100;  // Gera um número aleatório entre 0 e 99
}

void pre_order(NO *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->info);
        pre_order(raiz->esq);
        pre_order(raiz->dir);
    }
}

void in_order(NO *raiz)
{
    if (raiz != NULL)
    {
        in_order(raiz->esq);
        printf("%d ", raiz->info);
        in_order(raiz->dir);
    }
}

void pos_order(NO *raiz)
{
    if (raiz != NULL)
    {
        pos_order(raiz->esq);
        pos_order(raiz->dir);
        printf("%d ", raiz->info);
    }
}

void insere(NO **raiz, int val){
    if (*raiz == NULL){
        *raiz = (NO *)calloc(1, sizeof(NO));
        (*raiz)->info = val;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }else{
        if(val < (*raiz)->info){
            insere(&(*raiz)->esq, val);
        }else{
            insere(&(*raiz)->dir, val);
        }
    }
}
NO *buscar_naoRecursiva(NO *raiz, int val) {
    NO *r = raiz;  // Inicia o ponteiro 'r' na raiz
    while (r != NULL && r->info != val) {  // Continua até que 'r' seja NULL (fim da árvore)
        if (val < r->info) {
            r = r->esq;  // Continua para a subárvore esquerda
        } else {
            r = r->dir;  // Continua para a subárvore direita
        }  
    }
    return r;
}
NO *busca(NO *raiz, int val)
{
	if (raiz==NULL)
		return NULL;
	else
		if (raiz->info==val)
			return raiz;
		else
			if (val < raiz->info)
				return busca(raiz->esq, val);
			else
				return busca(raiz->dir, val);
}

NO *busca_pai(NO *raiz, NO *r)
{
    if (raiz->esq == r|| raiz->dir == r)
			return raiz;
		else
			if (r ->info < raiz->info)
				return busca_pai(raiz->esq, r);
			else
				return busca_pai(raiz->dir, r);
    return r;
}
int main()
{
    NO *raiz, *r, *pai;
    int op, val, i;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    raiz = NULL;
    do
    {   
        system("clear");
        printf("\n1 - Inserir Nó na Árvore");
        printf("\n2 - Mostrar Percurso");
        printf("\n3 - Randomizar a Árvore");
        printf("\n4 - Procurar Valor na Árvore");
        printf("\n5 - Digite o NÓ que deseja conhecer o pai");
        // case 6 remover um nó
        printf("\n0 - Sair");
        printf("\nDigite uma opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &val);
            insere(&raiz, val);
            break;
        
        case 2:
            if (raiz == NULL){
                printf("\nÁrvore Vazia!");
            }else{
                printf("\nPré-ordenado\n");
                pre_order(raiz);
                printf("\nIn ordenado\n");
                in_order(raiz);
                printf("\nPós ordenado\n");
                pos_order(raiz);
                printf("\n");
                esperar();
            }
            break;
            
        case 3:
            printf("\nRandomizando a árvore com valores aleatórios...\n");
            for (i = 0; i < 10; i++){
                insere(&raiz, randomizar());
            }
            printf("Árvore randomizada com sucesso!\n");
            esperar();
            break;
        
        case 4: 
            printf("\nDigite o valor a procurar: ");
			scanf("%d", &val);
			if (raiz==NULL)
					printf("\nArvore Vazia!\n");
			else{
					r = buscar_naoRecursiva(raiz, val);
					if (r==NULL)
						printf("\nValor nao existe na arvore!\n");
					else
						printf("\nValor encontrado: %d\n", r->info);

					}
				esperar();
				break;
        case 5:
            printf("\nDigite o valor que deseja conhecer o pai: ");
			scanf("%d", &val);
            if (raiz == NULL){
                printf("\nRaiz vazia\n");
            }
            else{
                r = busca(raiz, val);
                if(r == NULL){
                    printf("\nValor não existe");
                }else{
                    if(r == raiz){
                        printf("\nNó não possui pai");
                    }else{
                        pai = busca_pai(raiz, r);
                        printf("\n O pai do %d é o %d\n", r->info, pai->info);
                    }
                }
            }
        esperar();

        default:
            break;
        }
    } while (op != 0);

    return 0;
}
