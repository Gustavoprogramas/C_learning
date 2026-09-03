#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <windows.h>
#define ID_BOTAO_IMP 1001
#define ID_BOTAO_LIB 1002
#define ID_BOTAO_ADC 1003
#define ID_CX_TXT 1004
#define ID_BOTAO_REM 1005
#define ID_BOTAO_REMV 1006
#define ID_BOTAO_CNT 1007
#define ID_BOTAO_INV 1008

Pilha minhaPilha;
Pilha Invertida;
const char g_szClassName[] = "Pilhas";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_CREATE:
        CriaPilha();
        CreateWindow(
                     "BUTTON", "Imprimir Pilha",
                     WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                     300, 20, 150, 40, // X, Y, L, H
                     hwnd, (HMENU)ID_BOTAO_IMP, NULL, NULL
                     );
        CreateWindow(
                     "BUTTON", "Liberar Pilha",
                     WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                     300, 80, 150, 40,
                     hwnd, (HMENU)ID_BOTAO_LIB, NULL, NULL
                      );
       CreateWindow(
                    "BUTTON", "Adicionar valor",
                     WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                     300, 140, 150, 40,
                     hwnd, (HMENU)ID_BOTAO_ADC, NULL, NULL

                     );
       CreateWindow(
                    "EDIT", "",
                    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER,
                    150, 140, 150, 40,
                    hwnd, (HMENU)ID_CX_TXT, NULL, NULL

                     );
      CreateWindow(
                   "BUTTON", "Remover 1 da pilha",
                   WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                   300, 200, 150, 40,
                   hwnd, (HMENU)ID_BOTAO_REM, NULL, NULL

                   );
      CreateWindow(
                   "BUTTON", "Remover valor",
                   WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                   300, 260, 150, 40,
                   hwnd, (HMENU)ID_BOTAO_REMV, NULL, NULL
                   );
       CreateWindow(
                    "EDIT", "",
                    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER,
                    150, 260, 150, 40,
                    hwnd, (HMENU)ID_CX_TXT, NULL, NULL

                     );
      CreateWindow(
                   "BUTTON", "Contar tamanho da pilha",
                   WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                   300, 320, 190, 40,
                   hwnd, (HMENU)ID_BOTAO_CNT, NULL, NULL
                   );
      CreateWindow(
                   "BUTTON", "Inverter Pilha",
                   WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                   300, 380, 150, 40,
                   hwnd, (HMENU)ID_BOTAO_INV, NULL, NULL
                   );
      break;
    case WM_COMMAND:
        switch(LOWORD(wParam)) {
        case ID_BOTAO_IMP:
            imprime(&minhaPilha);
            break;
        case ID_BOTAO_ADC:
            char buffer[256];
            GetDlgItemText(hwnd, ID_CX_TXT, buffer, sizeof(buffer));
            if (buffer[0] != '\0'){
                int valor = atoi(buffer);
                push(&minhaPilha, valor);
            } else {
                MessageBox(hwnd, "Digitar um numero na caixa branca ao lado do botao", "Aviso", MB_OK | MB_ICONWARNING);
            }
        break;
        case ID_BOTAO_LIB:
            liberaPilha(&minhaPilha);
        break;
        case ID_BOTAO_REM:
            int valor;
            valor = pop(&minhaPilha);
            system("cls");
            printf("\nValor removido: %d", valor);
        break;
        case ID_BOTAO_REMV:
            char naosei[256];
            GetDlgItemText(hwnd, ID_CX_TXT, naosei, sizeof(naosei));
            if (naosei[0] != '\0'){
                int valor = atoi(naosei);
                remv(&minhaPilha, valor);
            } else {
                MessageBox(hwnd, "Digitar um numero na caixa branca ao lado do botao", "Aviso", MB_OK | MB_ICONWARNING);
            }
        break;
        case ID_BOTAO_CNT:
            contarelementos(&minhaPilha);
        break;
        case ID_BOTAO_INV:
            inverterpilha(&minhaPilha);
        break;

        }
        break;
        case WM_CLOSE:
            DestroyWindow(hwnd);

        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //classe da janela
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }


    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Exercicios",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);


    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}


