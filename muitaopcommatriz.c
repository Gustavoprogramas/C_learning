#include <stdio.h>
#include <stdlib.h>



int main () {

int matriz[4][4], transposta[4][4], matriztrocada[4][4], vetorsoma[4], vetormaior[4];
int par=0, somap=0, somas = 0;

for (int i=0; i<4; i++){
    vetormaior[i] = -29389;
    vetorsoma[i] = 0;
}
for (int i = 0,j=0; i<4; i++) {
    j=0;



    for (j; j<4; j++) {
        printf("%d linha %d coluna:\n", i+1, j+1);
        scanf("%d", &matriz[i][j]);
        vetorsoma[i] += matriz[i][j];
        if (matriz[i][j] % 2 == 0){
            par++;
        }
        if (i==j){
            somap += matriz[i][j];
        }
        if (i+j == 4) {
            somas += matriz[i][j];
        }
        matriztrocada[i][j] = matriz[i][j];

    }
}
//matriz capturada


for (int i = 0,j=0; i<4; i++) {
    j=0;
    printf("\n");
    for (j; j<4; j++) {
        if (j==0) {
            matriztrocada[i][0] = matriztrocada[i][2];
            matriztrocada[i][2] = matriz[i][0];
        }
    }
}
printf("\n\n");

printf("\nMatriz digitada: \n");
for (int i = 0,j=0; i<4; i++) {
    j=0;
    printf("\n");
    for (j; j<4; j++) {
        printf("%d ", matriz[i][j]);
                if (matriz[j][i] > vetormaior[i]){
        vetormaior[i] = matriz[j][i];
    }
    }
}
printf("\nMatriz transposta: \n");
for (int j = 0,i=0; j<4; j++) {
    i=0;
    printf("\n");

    for (i; i<4; i++) {
        printf("%d ", matriz[i][j]);
    }
}
printf("\nMatriz trocada: \n");
for (int i = 0,j=0; i<4; i++) {
    j=0;
    printf("\n");
    for (j; j<4; j++) {
        printf("%d ", matriztrocada[i][j]);
    }
}
printf("\nHa %d numeros pares na matriz.", par);
printf("\nA soma dos valores da diagonal principal eh: %d", somap);
printf("\nA soma dos valores da diagonal secundaria eh: %d", somas);


printf("\nSoma do valor de cada linha:\n");
for (int i=0; i<4; i++){
    printf("%d  ", vetorsoma[i]);
}
printf("\nMaior valor de cada coluna:\n");
for (int i=0; i<4; i++){
    printf("%d  ", vetormaior[i]);
}
}
