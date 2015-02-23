# include<stdio.h>
# include<stdlib.h>
# include<string.h>
/*# include<ncurses.h>*/
# include<curses.h>
# include<ctype.h>
//#define MALLOC(x) ((x *) malloc (sizeof(x)))

/*
   Ivan Carmo da Rocha Neto
   Bacharelado em Ciência da Computacao
   Universidade Federal da Bahia
   Programa Lista Encadeada em C usando Apontadores
*/

typedef struct ElemListaint{
   int chave;
   struct ElemListaint *ant, *prox;
}Listaint;


void inicializa(Listaint **l){
   *l = NULL;
}

int consulta(Listaint *l, int x){
   Listaint *p;
   int achou = 1;
   
   p = l;
   while(p){
      if( p -> chave == x){
         //printf("%d", achou);
         return(1);
      }else
         p = p -> prox;
   }
   //printf("%d", !achou);
   return (0);
}

Listaint *retornaApontElem(Listaint *l, int x){
   int achou = 0;
   
   while((l != NULL) && (!achou)){
      if(l -> chave == x)
         achou = 1;
      else
         l = l -> prox;
   }
   return (l);
}


void imprime(Listaint *l){
   if(l == NULL)
      printf("\nLista Vazia!");
   else{
      printf("\nLista de Inteiros: ");
      while(l){
        printf("%d  ", l -> chave);
        l = l -> prox;
      }
   }
   //printf("\n\nPressione Tecla... ");
   getchar();
   
}

int insere(Listaint **l, int x){
   Listaint *p;
   //int inserido = 1;
   
   if(!consulta(*l, x)){
      p = ((Listaint *)malloc(sizeof(Listaint)));
      p -> chave = x;
      p -> ant = NULL;
      p -> prox = *l;
      if ((*l) != NULL)
         (*l) -> ant = p;
      *l = p;
      return(1);
   }else
      return (0);
}

void remover(Listaint **l, int x){
   Listaint *p;
   int achou = 0;
   
   p = retornaApontElem(*l, x);
   if(p != NULL){
      if(p -> prox != NULL)
         p -> prox -> ant = p -> ant;
      if(p -> ant != NULL)
         p -> ant -> prox = p -> prox;
      else
         (*l) = p -> prox;
      free(p);
      achou = 1;
   }
   if(achou){
      printf("\nElemento Removido com Sucesso!\n");
      usleep(1000000);
   }else{
      printf("\nElemento nao Encontrado!\n");
      usleep(1000000);
   }
}


int main(){
   char op[1];
   Listaint *l;
   int a;

   inicializa(&l);
      for(;;){
         printf("\n\n");
         system("clear");
         printf("Programa Lista Encadeada!\n\n");
         printf("a. Insere na Lista;\n");
         printf("b. Remove da Lista;\n");
         printf("c. Consulta na Lista;\n");
         printf("d. Imprime Lista;\n");
         printf("s. SAIR.\n\n");
         printf("OPCAO: "); 
         gets(op);
         switch(toupper(op[0])){
            case 'A':{
               fflush(stdin);
               //system("clear");
               printf("\nDigite o Elemento a Inserir: ");
               scanf("%d", &a);
               a = insere(&l, a); //******************************************
               if(a)
                  printf("\nElemento Inserido com Sucesso!\n");
               else
                  printf("\nElemento ja existe!\n");
               usleep(1000000);
            }break;
            case 'B':{
               fflush(stdin);
               //system("clear");
               if(l == NULL){
                  printf("\nLista Vazia!");
                  getchar();
               }else{
                  printf("\nDigite o Elemento a Remover: ");
                  scanf("%d", &a);
                  remover(&l, a);
               }
            }break;
            case 'C':{
               fflush(stdin);
               if(l == NULL){
                  printf("\nLista Vazia!");
                  getchar();
               }else{
                  printf("\nDigite o Elemento a Consultar: ");
                  scanf("%d", &a);
                  a = consulta(l, a); //*******************************************
 //printf("{FONTE}33[x;yH");
                  if(a)
                    printf("\nValor encontrado na lista!!!\n");
                  else
                    printf("\nValor nao encontrado na lista!!!\n");
                  usleep(1000000);
                  if (a == consulta(l, a))
                     fflush(stdin);
               }
            }break;
            case 'D':{
               imprime(l);
            }break;
            case 'S':{
               fflush(stdin);
               printf("\nTem certeza? (S/N) ");
               gets(op);
               if(toupper(op[0]) == 'S'){
                  system("clear");
                  exit(0);
            }
            }break;
            default:{
               fflush(stdin);
               if(toupper(op[0]) != 'S')
                  printf("Opcao incorreta, digite novamente!");
               //usleep(1000000);
            }break;
         }
      }//while(toupper(op[0]) != 'S');
   return (0);
}