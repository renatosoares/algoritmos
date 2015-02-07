#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
/*
Considere a definição de um nó de lista abaixo:

    struct ListaOrdenada{
        int numero;
    struct ListaOrdenada *proximo;
    };
        * Escreva um programa que realize as seguintes
        * operações numa lista de nós struct ListaOrdenada:

-inserir: Insere um número na lista, de forma que o mesmo seja inserido de forma
ordenada, onde seu antecessor é menor que ele e seu sucessor é maior que ele.
-remover: remove um número da lista
-buscar: verifica se um número está presente na lista
-tamanho: conta a quantidade de números na lista
*/


int main(int argc, char **argv) {
  inserir(3);
  inserir(1);
  inserir(90);
  inserir(6);
  inserir(40);
  inserir(2);
  inserir(4);
  inserir(20);

  /* Testar ordenação da lista */
  int *values;
  values = get_list();
  int compare[8] = {1, 2, 3, 4, 6, 20, 40, 90};
  int i = 0;
  for(; i < 8; i++) {
    assert(compare[i] == values[i]);
  }

  /* Testes do metodo buscar */
  assert(tamanho() == 8);

  /* Testes do metodo buscar */
  assert(buscar(200) == 0);
  assert(buscar(20) == 1);

  /* Testes do metodo remover */
  remover(1);
  remover(3);
  remover(20);
  int *values2;
  values2 = get_list();
  int compare2[5] = {2, 4, 6, 40, 90};
  for(i = 0; i < 5; i++) {
    assert(compare2[i] == values2[i]);
  }

  print_list();

  return EXIT_SUCCESS;
}