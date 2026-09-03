#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/* FUN��ES DE MANIPULA��O DE PILHA

Pilha* CriaPilha ()               CRIA A PILHA

No* ins_ini (No* t, int a)  s      AUXILIAR DA INSER��O

void push (Pilha* p, int v)  s     INSER��O

No* ret_ini (No* l)    s           AUXILIAR DA REMO��O

int pop (Pilha* p)    s             REMOVE RETORNANDO O VALOR QUE FOI REMOVIDO

Pilha* liberaPilha (Pilha* p)  s    LIBERA A PILHA (CONSTRUIR)

void imprime (Pilha* p)  s   	   IMPRIMA A PILHA (CONSTRUIR)

int vaziaPilha(Pilha *p) s	   VERIFICA SE A PILHA EST� VAZIA, RETORNA 1 (CONSTRUIR)

*/

typedef struct no
{
    int info;
    struct no *prox;
}No;

typedef struct pilha
{
   No *Topo;
}Pilha;




int vaziaPilha(Pilha *p) {
    if (p->Topo == NULL) {

        return 1;
    }else {
    return 0;
    }


}
Pilha* CriaPilha (void)
{
     Pilha *p;
     p=(Pilha*)malloc(sizeof(Pilha));
     p->Topo = NULL;
   return p;
}

No* ins_ini (No* t, int a)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = a;
    aux->prox = t;
    return aux;
}

void push (Pilha* p, int v)
{
    p->Topo = ins_ini(p->Topo,v);
}

No* ret_ini (No* aux)
{
    No* p = aux->prox;
    free(aux);
    return p;
}

int pop (Pilha *p)
{
    int v;
    if (vaziaPilha(p))
    {
        printf("\n\n\t==> Pilha VAZIA, IMPOSSIVEL CONTINUAR.\b\n");
        exit(1); /* aborta programa */
    }
    v = p->Topo->info;
    p->Topo = ret_ini(p->Topo);
    return v;
}





Pilha* liberaPilha (Pilha* p) {
    No *l = p->Topo;
    No *aux;
    while(l!=NULL) {
        aux = l->prox;
        free(l);
        l = aux;
    }


}

void imprime (Pilha* p)  {
    No *t = p->Topo;
    system("cls");
    while (t!=NULL){

        printf("\n%d ", t->info);
        t=t->prox;
    }


}

void contarelementos (Pilha *p) {
    int cont = 0;
    No *t = p->Topo;
    while (t!=NULL) {
    cont++;
    t=t->prox;
    }
Pilha* inverterpilha (Pilha *p) {
    if (p == NULL || p->Topo == NULL){
        exit(1);
    }
    No *aux = NULL;
    No *proximo = NULL;
    No *t = p->Topo;
    while (t!=NULL){
        proximo = t->prox;
        t->prox = aux;
        aux = t;
        t = proximo;
    }
    p->Topo = aux;
}

void Removervalor(Pilha *p, int valor) {
    No* aux = NULL;
    No *t = p->Topo;
    while (t->info!=valor && t->info!=NULL){
        aux = t;
        t=t->prox;
    }
    if (t==NULL) {
        exit(1);
    }
    if (aux==NULL){
        p->Topo = t->prox;
    } else {
        aux->prox = t->prox;

    }
    free (t);



}

}






#endif // PILHA_H_INCLUDED
