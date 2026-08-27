#include <stdio.h>
#include <stdlib.h>

#define TAM 50

typedef struct No {
 int info;
 struct No *prox;

} No;

typedef struct lista {
    No *inicio;

} Lista;


void printarLista (Lista *l) {
    No *p = l->inicio;

    while (p != NULL) {
        printf("%d  ", p->info);
        p = p->prox;
    }
}

void inserirLista (Lista *L, int valor){
    Lista *aux;
    No *novo = (No*) malloc(sizeof(No));
    aux = L;
    novo->info = valor;
    novo->prox = aux->inicio;
    L->inicio = novo;

}


void inverterpos(Lista *L, int m, int n){

if (m==n||L->inicio ==NULL) return;
int pos1;
int pos2;
if (m<n){
    pos1=m;
    pos2=n;
}else {
    pos1=n;
    pos2=m;
}
No *aux= L->inicio;
No *alvo1 = NULL;
No *alvo2 = NULL;
int flag = 1;



while (aux!=NULL && flag<= pos2){
    if (flag == pos1){
        alvo1=aux;
    }
    if (flag == pos2){
        alvo2 = aux;
    }
    aux = aux->prox;
    flag++;
}
int temp;
    if (alvo1 != NULL && alvo2 != NULL){
        temp = alvo1->info;
        alvo1->info = alvo2->info;
        alvo2->info = temp;
    }




}
Lista* CriarLista() {
    Lista *aux = (Lista*) malloc (sizeof(Lista));

    aux->inicio = NULL;
    return aux;
}


int main() {

    int resp=1;
    int m, n;
    Lista *minhalista = CriarLista();
    Lista *outralista = CriarLista();
    int valor;

    printf("\nDigite a posicao m:\n");
    scanf("%d", &m);
    printf("\nDigite a posicao n:\n");
    scanf("%d", &n);
    while (resp==1) {
         printf("\nDigite o valor que quer adicionar na lista:\n");
            scanf("%d", &valor);
            inserirLista(minhalista, valor);

            printf("\nQuer inserir mais coisas na lista? S=1, N=0\n");
            scanf("%d", &resp);
    }
    inverterpos(minhalista, m, n);
   // printf("printando a listainvertida");
    printarLista(minhalista);

}
