#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int mouseParams[3];

  
    if (!SystemParametersInfo(SPI_GETMOUSE, 0, mouseParams, 0)) {
        printf("Erro ao ler as configuracoes do mouse.\n");
        system("Pause");
        return 1;
    }

    
    if (mouseParams[2] == 0) {
        printf("A aceleracao nativa ja esta desativada.\n");
        system("Pause");
        return 0;
    }

    mouseParams[2] = 0;

    
    if (SystemParametersInfo(SPI_SETMOUSE, 0, mouseParams, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
        printf("Aceleracao do mouse desativada com sucesso!\n");
    } else {
        printf("Falha ao alterar a configuracao. O sistema pode estar restringindo a API.\n");
    }
    system("Pause");
    return 0;
}
// gcc mouse_fix.c -o mouse_fix.exe
