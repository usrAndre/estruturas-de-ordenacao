#ifndef FILALIVRO_H_INCLUDED
#define FILALIVRO_H_INCLUDED

typedef struct fila Fila;

Fila* fila_cria(void);
void fila_insere(Fila* f, float v);
float fila_retira(Fila* f);
int fila_vazia(Fila* f);
void fila_libera(Fila* f);
void fila_imprime(Fila* f);


#endif // FILALIVRO_H_INCLUDED
