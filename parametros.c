#include <stdio.h>
#include <stdlib.h>
typedef struct No {
    int info;
    struct No *prox;
}No;
typedef struct lista {
    No* inicio;
}Lista;

Lista *inserirL(Lista *L, int v){
    No *novo = (No*)malloc (sizeof(No));
    novo ->info = v;
    novo -> prox = L->inicio;
    L -> inicio = novo;
    return L;
}


int parametros(Lista *L, int m, int n) {
    if (L == NULL || m < 0 || n < 0)
        return 1;

    No *atualm = L->inicio;
    No *atualn = L->inicio;

    for (int i = 0; i < m && atualm != NULL; i++)
        atualm = atualm->prox;

    for (int i = 0; i < n && atualn != NULL; i++)
        atualn = atualn->prox;

    if (atualm == NULL || atualn == NULL)
        return 1;  

    int temp = atualm->info;
    atualm->info = atualn->info;
    atualn->info = temp;

    return 0;
}

void printar(Lista *L){
    No* aux = L->inicio;
    while (aux!=NULL){
        printf("%d     ", aux->info);
        aux = aux->prox;
    }
}

int main () {
    Lista *L = (Lista*) malloc(sizeof(Lista));
    L->inicio = NULL;
    int m, n;
    inserirL(L, 1);
    inserirL(L, 2);
    inserirL(L, 3);
    inserirL(L, 4);
    inserirL(L, 5);
    printf("Lista: \n");
    printar(L);
    printf("\nValor de m-    ");
    scanf("%d", &m);
    printf("\nValor de n-    ");
    scanf("%d", &n);
    
    int controle = parametros(L, m, n);
    if (controle == 0){
        printf("Lista: \n");
        printar(L);
    }else 
    printf("\nvalor invalido para m ou n");


}
