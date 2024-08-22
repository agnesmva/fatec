#include <stdio.h>
#include <stdlib.h>

struct dados
{
    int info;
    struct dados *prox;

};

typedef struct dados NO;

int main()
{
    NO *p, *q;
    p =(NO *)calloc(1, sizeof(NO));
    q =(NO *)calloc(1, sizeof(NO));

    p -> info = 10; // -> serve para chamar, como se fosse p.info = 10;

    q -> info = 15;

    p -> prox = q;
    q -> prox = NULL;

    printf("A ponta dessa lista é %d\n", p ->info);

    p = p->prox;
    printf("A ponta dessa lista é %d\n", p ->info);
    printf("A ponta dessa lista é %d\n", q ->info);
    return 0;
}
