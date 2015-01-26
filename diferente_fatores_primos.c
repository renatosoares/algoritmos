#include <stdio.h>
#include <stdlib.h>

struct ListaNumero *inicio = NULL;
/*
Escreva um programa que computa
o número de diferentes fatores
primos de um inteiro positivo.
*/ /*No final tem a questão inteira*/

struct ListaNumero {
  int numero;
  struct ListaNumero *proximo;
};

int MostrarFatoresPrimos(unsigned n){
    unsigned x = n;
    unsigned resto;
    unsigned div = 2;
    int exp = 0;
    int i = 1;
    if(x < 2) { 
        return x;  
    }
    while(x > 1)
    {
        resto = x % div;
        if(resto == 0)
        {
            while(resto == 0)
            {
                x = (int)(x/div);
                exp += 1;
                resto = x % div;
            }  
            if(x > 1) i++; 
        }
        else
        {
            exp = 0;  /* reinicia expoente */
            div += 1; /* próximo divisor */
        }  
    }  
      return i;
}  



int inserirFim(int numero) {
  struct ListaNumero *novo, *ultimo;
  int retorno = 1;
  novo = (struct ListaNumero*) malloc(sizeof(struct ListaNumero));
  if (novo == NULL) { /* Verifica se a memória foi alocada */
    retorno = -1;
  } else {
    novo->numero = numero;
    novo->proximo = NULL; /* O novo é o fim da lista */
    if (inicio == NULL) { /* Se a lista estiver vazia */
      inicio = novo; /* o novo será o único elemento da lista */
    } else { /* Se ja houver elementos na lista */
      /* Percorre a lista para encontrar o último elemento */
      ultimo = inicio;
      while (ultimo->proximo != NULL)
        ultimo = ultimo->proximo;
      ultimo->proximo = novo; /* Atualiza referência do último */
    }
  }

  return retorno;
}

void mostraNumeros() {
  struct ListaNumero * atual;
  atual = inicio;
  while (atual != NULL) {
    if (atual->numero != 0)
    {
      printf("%d : %d \n", atual->numero, MostrarFatoresPrimos(atual->numero)); 
    }
    
    
    atual = atual->proximo;
  }
}

int main(int argc, char const *argv[])
{
  int valor;
  do
  {

    scanf("%d", &valor);
    if (valor > 1000000)
    {
      continue;
    }
    inserirFim(valor);
  }while(valor != 0);
 
  
  printf("\n\n\n\n");
  
  mostraNumeros();

  
  return 0;
}


/*
1850. Conte os Fatores
Problema: CFATORES

Escreva um programa que computa o número de diferentes fatores primos de um inteiro positivo.
Entrada

A entrada consistirá de uma série de inteiros positivos. Cada linha possui somente um número. O valor máximo de um número é 1000000. O fim da entrada é indicado por um número igual a 0. Esse número não deve ser considerado como parte do conjunto de teste.
Saída

O programa deve imprimir cada resultado em uma linha diferente, seguindo o formado dado no exemplo de saída.
Exemplo

Entada:
289384
930887
692778
636916
747794
238336
885387
760493
516650
641422
0

Saída:
289384 : 3
930887 : 2
692778 : 5
636916 : 4
747794 : 3
238336 : 3
885387 : 2
760493 : 2
516650 : 3
641422 : 3

*/
