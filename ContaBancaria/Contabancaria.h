#ifndef CONTABANCARIA_H_INCLUDED
#define CONTABANCARIA_H_INCLUDED

// definição do tipo
typedef struct
{
    int numero;
    double saldo;
} ContaBancaria;
// cabeçalho das funções
void Inicializa(ContaBancaria* conta, int numero, double saldo);
void Deposito (ContaBancaria* conta, double valor);
void Saque (ContaBancaria* conta, double valor);
void Imprime (ContaBancaria conta);

#endif // CONTABANCARIA_H_INCLUDED
