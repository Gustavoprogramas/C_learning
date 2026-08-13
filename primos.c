#include <stdio.h>
#include <stdlib.h>

int main () {
    int num, controle=0;
    printf("Digite um numero:\n");
    scanf("%d", &num);
    if (num<3) {
        printf("\n%d eh primo.", num);
    }else {
         for (int i = 2; i<num; i++){
    if (num%i == 0) {
        printf("\n%d nao eh primo. ", num);
        controle = 1;
        i = num+2;
    } else if (controle==0){
        for (int j = num + 1; j<num*10; j++) {
                if (num%j == 0) {
                    printf("\n%d nao eh primo. ", num);
                    j = num*10+2;
                }
            }
    }

if (controle==0){
        printf("\n%d eh primo.", num);
                    i = num + 2;

}




  }

    }



}
