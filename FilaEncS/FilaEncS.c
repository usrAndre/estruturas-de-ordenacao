#include <stdio.h>
#include <stdlib.h>
#include "FilaEncS.H"

//#include<alloca.h>

 typedef int telem;

 typedef struct no{
    telem dado;
    struct no* prox;
 }tno;

 typedef struct fila{
     tno* inicio;
     tno* fim;
 }tfila;

 void criar(tFila *F){
    F->inicio = F->fim = NULL;
 }

 int vazia(tFila F){
    return (F.inicio == NULL && F.fim == NULL);
 }

 int primeiro(tFila f, telem *elem){
    if (vazia(F))
        return 0;
    *elem = (F.inicio)->dado;
    return 1;
 }

 int inserir(tFila *F, telem valor){
    tno* novo;

    novo = (tno)malloc(sizeof(tno));
    if novo == NULL
        return 0;
    novo->dado = valor;
    novo->prox = NULL;

    if (vazia(*F))
        F->inicio = novo;
    else
        (F->fim)->prox = novo;

    F->fim = novo;

    return 1;
 }

 int remover(tFila *F, telem valor){
    tno *aux;
    if (vazia(*F))
        return 0;

    primeiro(*F, valor);

    if (F->inicio == f->fim)
        F->fim = NULL;

    aux = F->inicio;
    F->inicio =(F->inicio)->prox;
    free(aux);

    return 1;
 }
