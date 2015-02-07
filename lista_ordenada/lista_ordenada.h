#ifndef LISTA_ORDENADA_H_
#define LISTA_ORDENADA_H_

typedef struct ListaOrdenada {
  int numero;
  struct ListaOrdenada *proximo;
} ListaOrdenada;

void inserir(int numero);

int remover(int numero);

int buscar(int numero);

int tamanho();

void print_list();

int *get_list();

#endif
