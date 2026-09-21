#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int info;
    struct No* prox;
}No;
typedef struct Lista {
    No* inicio;
}Lista;

No* inserirLista (No *antigo, int valor){
    No *novo;
    novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->prox = antigo;
    return novo;

}
void insereL_inicio (Lista *L, int v){
    L->inicio=inserirLista(L->inicio, v);
}
Lista *comapara(Lista *l1, Lista *l2){
    
    int v = l1->inicio->info;
    while (v != 0){
        int dig = v%10;
        insereL_inicio(l2, dig);
        v = v/10;
       
        
    }
    return l2;
}

void printar(Lista *l){
    No* aux = l->inicio;
    while (aux!=NULL){
        printf("%d,   ",aux->info);
        aux = aux->prox;
    }
}
int main () {
    Lista* l1 = (Lista*) malloc (sizeof(Lista)); 
    Lista* l2 = (Lista*) malloc (sizeof(Lista));
    l1->inicio = NULL;
    l2->inicio = NULL;
    insereL_inicio(l1, 3314);
    l2 = comapara(l1, l2);
    printar(l2);

}
