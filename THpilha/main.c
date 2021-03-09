#include <stdio.h>
#include <stdlib.h>
#define A 5
#define E 4
#define I 3
#define O 2
#define U 1


//Interface pilha.h
typedef struct pilha Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);

//pilha.c

struct lista{
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

struct pilha{
    Lista* prim;
};

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push(Pilha* p, float v){
    Lista* n = (Lista*)malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

float pilha_pop(Pilha* p){
    Lista* t;
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

int pilha_vazia(Pilha* p){
    return(p->prim == NULL);
}

void pilha_libera(Pilha* p){
    Lista* q = p->prim;
    while (q!=NULL){
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

//imprime
void pilha_imprime(Pilha* p)
{
    Lista* q;
    for(q=p->prim; q!=NULL; q=q->prox)
        printf("%f\n", q->info);
}



int main()
{
    Pilha* torre1;
    torre1 = pilha_cria();
    pilha_push(torre1, A);
    pilha_push(torre1, E);
    pilha_imprime(torre1);

    return 0;
}
