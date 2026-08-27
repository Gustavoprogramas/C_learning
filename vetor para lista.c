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



void inserirLista (Lista *L, int valor){
    Lista *aux;
    No *novo = (No*) malloc(sizeof(No));
    aux = L;
    novo->info = valor;
    novo->prox = aux->inicio;
    L->inicio = novo;

}

Lista* CriarLista() {
    Lista *aux = (Lista*) malloc (sizeof(Lista));

    aux->inicio = NULL;
    return aux;
}

int copiarParaVetor(Lista *L, int arry[], int tamarry) {
    No *p = L->inicio;
    int i = 0;
    while (p!=NULL && i < tamarry){
        arry[i] = p->info;
        i++;
        p = p->prox;
    }
    return i;




}


Lista* criarListaDoVetor(int arry[], int tamarry){
Lista *novaLista = CriarLista();
        for (int i = tamarry-1; i >=0; i--){
        inserirLista(novaLista, arry[i]);
}
return novaLista;
}


void printarLista (Lista *l) {
    No *p = l->inicio;
    while (p != NULL) {
        printf("%d  ", p->info);
        p = p->prox;
    }
}
int main() {

    int resp=1;
    int tamarry=0;
    int arry[TAM];
    Lista *minhalista = CriarLista();
    Lista *outralista = CriarLista();
    printf("\nTam max = %d", TAM);
    int valor;

    do{
        printf("\nTam do vetor? Max:50\n");
    scanf("%d", &tamarry);
    }while (tamarry<0 || tamarry>50);

        for (int i = 0; i < tamarry; i++){
        printf("\nElemento %d do vetor:\n", i+1);
        scanf("%d", &arry[i]);
        }


    printf("\nVetor em lista:\n");
    Lista *listavetor = CriarLista();
    listavetor = criarListaDoVetor(arry, tamarry);
    printarLista(listavetor);


    }



