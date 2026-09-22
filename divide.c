#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int info;
    struct No *prox;
} No;
typedef struct lista
{
    No *inicio;
} Lista;

Lista *inserirL(Lista *L, int v)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->info = v;
    novo->prox = L->inicio;
    L->inicio = novo;
    return L;
}
void printar(Lista *L)
{
    No *aux = L->inicio;
    while (aux != NULL)
    {
        printf("%d     ", aux->info);
        aux = aux->prox;
    }
}

Lista *divide (Lista*L){
    int k, i=0;
    No* aux = L->inicio;
    No* temp = L->inicio;
    printf("\nValor de k: ");
    scanf("%d", &k);
    while (aux!=NULL && i<k){
        temp = aux;
        aux=aux->prox;
        
        i++;
    }
    Lista*P = (Lista *)malloc(sizeof(Lista));
    P->inicio = aux;
    temp->prox = NULL;
    return P;
}
int main()
{
    Lista *L = (Lista *)malloc(sizeof(Lista));
    Lista *P = (Lista *)malloc(sizeof(Lista));
    L->inicio = NULL;
    P->inicio = NULL;
    inserirL(L, 1);
    inserirL(L, 2);
    inserirL(L, 3);
    inserirL(L, 4);
    inserirL(L, 5);
    printf("Lista: \n");
    printar(L);
    P = divide(L);
    printf("Lista L: \n");
    printar(L);
    printf("\nLista P: \n");
    printar(P);
}
