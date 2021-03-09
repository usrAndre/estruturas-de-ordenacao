#include <stdio.h>
#include <stdlib.h>
#include "FilaLivro.h"

struct lista{
    float info;
    struct lista* prox;
};

typedef struct lista Lista;

struct fila{
    Lista* ini;
    Lista* fim;
};

Fila* fila_cria(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere(Fila* f, float v)
{
    Lista* n = (Lista*)malloc(sizeof(Lista));
    n->info = v;
    n->prox = NULL;
    if(f->fim != NULL)
        f->fim->prox = n;
    else
        f->ini = n;
    f->fim = n;
}

float fila_retira(Fila* f)
{
    Lista* t;
    float v;
    if (fila_vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(t);
    return v;
}

int fila_vazia(Fila* f)
{
    return(f->ini == NULL);
}

void fila_libera(Fila* f)
{
    Lista* q = f->ini;
    while (q != NULL){
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

void fila_imprime(Fila* f)
{
    Lista* q;
    for(q=f->ini; q!=NULL; q=q->prox)
        printf("%f\n", q->info);
}
