#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"



ListaOrdenada *inicio = NULL;

void inserir(int x) {
  ListaOrdenada *novo,
                *aux = NULL,
                *item = inicio;
  int cont = 1;

  novo = (ListaOrdenada *) malloc(sizeof(ListaOrdenada));
  novo->numero = x;

  while (item != NULL && cont) {
    if (x < item->numero) {
      cont = 0;
    } else {
      aux  = item;
      item = item->proximo;
    }
  }

  novo->proximo = item;
  if (aux == NULL)
    inicio = novo;
  else
    aux->proximo = novo;
}

int remover(int numero) {
  ListaOrdenada *l, *prev = NULL;
  l = inicio;

  while(l != NULL) {
    if(l->numero == numero) {
      if(prev == NULL) {
        inicio = l->proximo;
      }
      else {
        prev->proximo = l->proximo;
      }

      free(l);
      return 1;
    }
    prev = l;
    l = l->proximo;
  }
  return 0;
}


int buscar(int numero) {
  ListaOrdenada *l = inicio;

  while(l != NULL) {
    if(l->numero == numero)
      return 1;
    l = l->proximo;
  }
  return 0;
}

int tamanho() {
  int count = 0;
  ListaOrdenada *cur;
  if(inicio != NULL) {
    cur = inicio;
    count++;

    while(cur->proximo != NULL) {
      cur = cur->proximo;
      count++;
    }
  }
  return count;
}

void print_list() {
  ListaOrdenada *l;

  if(inicio != NULL) {
    l = inicio;

    while(l != NULL) {
      printf("%d", l->numero);
      printf(" -> ");
      l = l->proximo;
    }
  }
  printf("\n");
}

int *get_list() {
  int ret[50];
  int *retorna;
  ListaOrdenada *l;
  int i = 0;

  if(inicio != NULL) {
    l = inicio;
    ret[i++] = l->numero;

    while(l->proximo != NULL) {
      ret[i++] = l->proximo->numero;
      l = l->proximo;
    }
  }
  retorna = ret;
  return retorna;
}
