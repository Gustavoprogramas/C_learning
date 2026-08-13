#include <stdio.h>
#include <stdlib.h>

int main (){
int vetor[11];
int maior = -214748364, menor = 214748364, posicaoma, posicaomn, num;
for (int i = 1; i < 11 ; i++) {
    printf("%d elemento do vetor:\n", i);
    scanf("%d", &num);
    vetor[i] = num;
    if (vetor[i] < menor) {
        menor = vetor[i];
        posicaomn = i;
    }
    if (vetor[i] > maior) {
        maior = vetor[i];
        posicaoma = i;
    }



}
printf("\n%d na posicao %d foi o maior numero \n %d na posicao %d foi o menor numero.",maior, posicaoma, menor, posicaomn);

}
