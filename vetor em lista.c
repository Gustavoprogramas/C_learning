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


int main() {

    int resp=1;
    int tamarry=0;
    int arry[TAM];
    Lista *minhalista = CriarLista();
    Lista *outralista = CriarLista();
    printf("\nTam max = %d", TAM);
    int valor;


    while (resp==1) {
         printf("\nDigite o valor que quer adicionar na lista:\n");
            scanf("%d", &valor);
            inserirLista(minhalista, valor);
            tamarry++;
            printf("\nQuer inserir mais coisas na lista? S=1, N=0\n");
            scanf("%d", &resp);
    }

    int vetor = copiarParaVetor(minhalista, arry, tamarry);

    printf("\nLista em vetor:\n");
    for (int i = 0; i < vetor; i++){
        if (i == vetor - 1){
            printf("%d ", arry[i]);
        }else {
            printf("%d, ", arry[i]);
        }

    }


}
