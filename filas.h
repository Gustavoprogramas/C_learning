#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

typedef struct nos
{
int info;
struct nos *prox;
}Nos;
typedef struct fila
{
Nos * ini;
Nos * fim;
} Fila;
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
        exit(1);
    }
    v = p->Topo->info;
    p->Topo = ret_ini(p->Topo);
    return v;
}





void liberaPilha (Pilha* p) {
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

    while (t!=NULL){

        printf("\n%d ", t->info);
        t=t->prox;
    }
}

int VaziaFila (Fila* f)
{
if (f->ini==NULL) return 1;
return 0;
}

Fila* CriaFila ()
{
Fila* f = (Fila*) malloc(sizeof(Fila));
f->ini = f->fim = NULL;
return f;
}
Nos* ins_fim (Nos *fim, int A)
{
Nos *p = (Nos*)malloc(sizeof(Nos));
p->info = A;
p->prox = NULL;
if (fim != NULL) {
    fim->prox = p;
return p;
}

}
void InsereFila (Fila* f, int v)
{
f->fim = ins_fim(f->fim,v);
if (f->ini==NULL) /* fila antes vazia? */
f->ini = f->fim;
}
Nos* retira_ini (Nos* ini)
{
Nos* p = ini->prox;
free(ini);
return p;
}
int RetiraFila (Fila* f)
{
int v;
if (VaziaFila(f))
{
printf("Fila vazia.\n");
exit(0); /* aborta programa */
}
v = f->ini->info;
f->ini = retira_ini(f->ini);
if (f->ini == NULL) /* fila ficou vazia? */
f->fim = NULL;
return v;
}
void imprimeFila (Fila* f)
{
Nos* q;
printf("\n\t\t");
for (q=f->ini; q!=NULL; q=q->prox)
{
printf("%d - ",q->info);
}
printf("\n");
}
Fila* liberaFila (Fila* f)
{
Nos* q = f->ini;
while (q!=NULL)
{
Nos* t = q->prox;
free(q);
q = t;
}
free(f);
return NULL;
}
void SepararFilas(Fila* F1, Fila* FI, Fila* FP){
        while (!VaziaFila(F1)){
            int valor = RetiraFila(F1);
            if (valor%2==0){
                InsereFila(FP, valor);
            }else {
                InsereFila(FI, valor);
            }
        }
}
void inverterFila(Fila* f){
    if (!VaziaFila(f)){
        int valor = RetiraFila(f);
        inverterFila(f);
        InsereFila(f, valor);
    }

}
void colocarfilhanapilha(Fila* f, Pilha* Maiorq20, Pilha* Menorq20){

    while(!VaziaFila(f)){
        int valor = RetiraFila(f);
        if (valor>20){
            push(Maiorq20, valor);
        }else {
            push(Menorq20, valor);
        }
    }
}
#endif // FILA_H_INCLUDED
