#include <stdlib.h>
#include <stdio.h>
typedef struct No {
    int info;
    struct No *prox;
}No;

typedef struct  lista
{
    No* inicio;
}Lista;

No *inserirLista(No *antigo, int valor)
{
    No *novo;
    novo = (No *)malloc(sizeof(No));
    novo->info = valor;
    novo->prox = antigo;
    return novo;
}
void insereL_inicio(Lista *L, int v)
{
    L->inicio = inserirLista(L->inicio, v);
}

int listaarry (Lista * l, int arry[]){
    No* aux = l->inicio;
    int i=0;
   
    while(aux!=NULL){
        arry[i] = aux->info;
        aux = aux->prox;
        i++;
    }
    return i;
}
int main () {
    Lista* l1 = (Lista*)malloc(sizeof(Lista));
    l1->inicio = NULL;
    insereL_inicio(l1, 1);
    insereL_inicio(l1, 2);
    insereL_inicio(l1, 3);
    insereL_inicio(l1, 4);
    int arry[10];
    int quantidade = listaarry(l1, arry);
    
    for(int i = 0; i<quantidade ; i++){
        printf("%d   ", arry[i]);
    }
}
