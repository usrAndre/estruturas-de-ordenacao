#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int dado, inicio;
    struct Fila *prox;
}fila;


void criaFila(fila *f){
    f->inicio=NULL;
}

int push(fila *f, int dado){
    fila *aux=(fila**) malloc (sizeof(fila*));
    if (aux==NULL) { printf ("ERROW"); return 0; }
    aux->dado = dado;
    aux->prox = NULL;

    if(f->inicio==NULL) {
        f->inicio=aux; }

    else {
        fila *atual=(fila**) malloc (sizeof(fila*));
        if (atual==NULL) { printf ("ERROW2"); return 0; }

        atual=f->inicio;
        while(atual!=NULL){ atual = atual->prox; }
        atual->prox = aux;

    }
    printf("Inserção realizada com sucesso!\n");
    return aux;
}

int pop(fila *f){
    fila *aux=(fila**) malloc (sizeof(fila*));
    if (aux==NULL) { printf ("ERROW3"); return 0; }
    aux=f->inicio;
    f->inicio=aux->prox;
    free(aux);
    printf("Remoção feita com sucesso!\n");
}

int main (){

    int nt, num;
    fila *f=(fila**) malloc (sizeof(fila*));
    if (f==NULL) { printf ("ERROW ANIMAL"); return 0; }

    criaFila(f);

    printf("digite o numero de termos: ");
    scanf(" %d", &nt);

    for(int i=0; i<nt; i++){
        printf("Digite o %d termo: ", i+1);
        scanf(" %d", &num);
        f = push(f, num);
        printf("------------//-----------\n");
    }

    for(int j=0; j<nt; j++){
        pop(f);
    }

}
