/**********************\   
    dlista.c * 
\**********************/   
#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>   
#include "dlista.h"   
#include "dlista_function.h"   

int main (void)   
{   

  int escolha = 0,pos;   
  char *dado;   
  dado = malloc(50);   
  dl_Lista *lista;   
  dl_elemento *pilote = NULL;   
  lista = (dl_Lista *) malloc (sizeof(dl_Lista));   

  inicialização(liste);   

  while( escolha!= 7){   
    escolha = menu(lista);   
    switch(escolha){   
      case 1:   
             printf("Entre um elemento: ");   
      scanf("%s",dado);   
      getchar();   
      if(lista->tamanho == 0)   
               inserção_em_uma_lista_vazia(lista,dado);   
      else   
               ins_início_lista (lista, dado);   
      printf("%d elementos: início=%s,fim=%s ",   
        lista->tamanho,lista->início->dado,lista->fim->dado);   
      exibe(lista);   
      break;   
      case 2:   
      printf("Entre um elemento: ");   
      scanf("%s",dado);   
      getchar();   
      ins_fim_lista (lista, dado);   
      printf("%d elementos: início=%s,fim=%s ",   
        lista->tamanho,lista->início->dado,lista->fim->dado);   
      exibe(lista);   
      break;   
      case 3:   
      if(lista->tamanho == 1){   
               printf("Utilizar a inserção no início ou no fim (Entrar Menu: 1 ou 2)\n");   
        break;   
      }   
      printf("Entre um elemento:");   
      scanf("%s",dado);   
      getchar();   
      do{   
                 printf("Entre a posição:");   
   scanf("%d",&pos);   
      }while (pos < 1 || pos > lista->tamanho);   
      getchar();   
      ins_antes(lista,dado,pos);   
      printf("%d elementos: início=%s fim=%s ",   
        lista->tamanho,lista->início->dado,lista->fim->dado);   
      exibe(lista);   
      break;   
      case 4:   
      if(lista->tamanho == 1){   
       printf("Utilizar a inserção no início ou no fim (Entrar Menu: 1 ou 2)\n");   
       break;   
      }   
      printf("Entre um elemento : ");   
      scanf("%s",dado);   
      getchar();   
      do{   
                 printf("Entre a posição: ");   
   scanf("%d",&pos);   
      }while (pos < 1 || pos > lista->tamanho);   
      getchar();   
      ins_depois(lista,dado,pos);   
      printf("%d elementos: início=%s,fim=%s ",   
        lista->tamanho,lista->início->dado,lista->fim->dado);   
      exibe(lista);   
      break;   
      case 5:   
      do{   
                 printf("Entre a posição: ");   
   scanf("%d",&pos);   
      }while (pos < 1 || pos > posição->tamanho);   
      getchar();   
      remov(posição,pos);   
      if(posição->tamanho != 0)   
               printf("%d elementos: início=%s,fim=%s ",   
          posição->tamanho,posição->início->dado,posição->fim->dado);   
      else   
               printf("posição vazia: %d elementos",posição->tamanho);   
      exibe(posição);   
      break;   
      case 6:   
      destruir(posição);   
      printf("a posição foi destruída: %d elementos\n",posição->tamanho);   
      break;   
    }   
  }   
  return 0;   
}   
/* -------- FIM dlista.c --------- */   