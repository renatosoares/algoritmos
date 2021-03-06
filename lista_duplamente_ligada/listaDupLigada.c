#include <stdio.h>
#include <stdlib.h>
struct ListaDuplaDado { 
    int dado; 
    struct ListaDuplaDado *proximo, *anterior; 
}; 
struct ListaDupla { 
    struct ListaDuplaDado *inicio, *fim; 
    int tamanho;
}; 

void inicializacao (struct ListaDupla *lista){   
  lista->inicio = NULL;   
  lista->fim = NULL;   
  lista->tamanho = 0;   
} 

int insercao_em_uma_lista_vazia (struct ListaDupla * lista, int dado){   
  struct ListaDuplaDado *novo_elemento;
  novo_elemento = (struct ListaDuplaDado*) malloc(sizeof(struct ListaDuplaDado));
  if (novo_elemento == NULL)
  {
  	return -1;
  }  
  novo_elemento->dado = dado;   
  novo_elemento->anterior = NULL;   
  novo_elemento->proximo = NULL;   
  lista->inicio = novo_elemento;   
  lista->fim = novo_elemento;   
  lista->tamanho++;   
  return 0;   
}

int ins_inicio_lista (struct ListaDupla * lista, int dado){   
  struct ListaDuplaDado *novo_elemento;   
   novo_elemento = (struct ListaDuplaDado*) malloc(sizeof(struct ListaDuplaDado));
  if (novo_elemento == NULL)
  {
  	return -1;
  }  
  novo_elemento->dado = dado;   
  novo_elemento->anterior = NULL;   
  novo_elemento->proximo = lista->inicio;   
  lista->inicio->anterior = novo_elemento;   
  lista->inicio = novo_elemento;   
  lista->tamanho++;   
  return 0;   
} 

void inverter(struct ListaDupla *lista){   
	struct ListaDuplaDado *em_curso;   
	em_curso = lista->fim;   
	while(em_curso != NULL){   
	 printf("%d : ",em_curso->dado);   
	 em_curso = em_curso->anterior;   
	}   
	printf("\n");   
}

int ins_depois(struct ListaDupla * lista, int dado, int pos){   
  int i;   
  struct ListaDuplaDado *novo_elemento, *em_curso;
  novo_elemento = (struct ListaDuplaDado*) malloc(sizeof(struct ListaDuplaDado));   
  if (novo_elemento == NULL) return -1;   
  novo_elemento->dado = dado;   
  em_curso = lista->inicio;   
  for (i = 1; i < pos; ++i) em_curso = em_curso->proximo;   
  novo_elemento->proximo = em_curso->proximo;   
  novo_elemento->anterior = em_curso;   
  if(em_curso->proximo == NULL) lista->fim = novo_elemento;   
  else  em_curso->proximo->anterior = novo_elemento;   
  em_curso->proximo = novo_elemento;   
  lista->tamanho++;   
  return 0;   
}

int ins_antes(struct ListaDupla * lista, int dado, int pos){   
  int i;   
  struct ListaDuplaDado *novo_elemento, *em_curso; 
  novo_elemento = (struct ListaDuplaDado*) malloc(sizeof(struct ListaDuplaDado));  
  if (novo_elemento == NULL) return -1;   
  novo_elemento->dado = dado;   
  em_curso = lista->inicio;   
  for (i = 1; i < pos; ++i) em_curso = em_curso->proximo;   
  novo_elemento->proximo = em_curso;   
  novo_elemento-> anterior = em_curso->anterior;   
  if(em_curso->anterior == NULL) lista->inicio = novo_elemento;   
  else em_curso->anterior->proximo = novo_elemento;   
  em_curso->anterior = novo_elemento;   
  lista->tamanho++;   
  return 0;   
}   

void inserirMeio(struct ListaDupla * lista, int n)
{
  int meio;
  meio = lista->tamanho / 2;
  ins_depois(lista, n, meio);
}   

void inserirOrdenado(struct ListaDupla * lista, int nValor)
{
  struct ListaDuplaDado *dadoComparado;
  dadoComparado = lista->inicio;
  int posicao = 0;
  while(dadoComparado != NULL)
  {

    if (nValor < dadoComparado->dado)
    {

      ins_antes(lista, nValor, posicao);
      break;
    }else
    {
   
      
      posicao++;
      dadoComparado = dadoComparado->proximo;
      if(dadoComparado->proximo == NULL)
      {
        ins_depois(lista, nValor, posicao);
        break;
      }else if (nValor < dadoComparado->dado)
      {
        posicao++;
        ins_antes(lista, nValor, posicao);
        break;
      } 

    }    
   
    
  }
 
}

void exibe(struct ListaDupla *lista){   
 	struct ListaDuplaDado *em_curso;   
 	em_curso = lista->inicio;   
 	printf("[ ");   
 	while(em_curso != NULL){   
 	  printf("%d ",em_curso->dado);   
 	  em_curso = em_curso->proximo;   
 	}   
 	printf("]\n");   
}   

int remov(struct ListaDupla * lista, int pos){   
  int i;   
  struct ListaDuplaDado *remov_elemento, *em_curso;   
  if(lista->tamanho == 0) return -1;   
  if(pos == 1){ /* remoção do 1° elemento */   
    remov_elemento = lista->inicio;   
    lista->inicio = lista->inicio->proximo;   
    if(lista->inicio == NULL) lista->fim = NULL;   
   /* else lista->inicio->anterior == NULL;   */
  }else if(pos == lista->tamanho){ /* remoção do último elemento */   
    remov_elemento = lista->fim;   
    lista->fim->anterior->proximo = NULL;   
    lista->fim = lista->fim->anterior;   
  }else { /* remoção em outro lugar */   
    em_curso = lista->inicio;   
    for(i=1;i<pos;++i) em_curso = em_curso->proximo;   
    remov_elemento = em_curso;   
    em_curso->anterior->proximo = em_curso->proximo;   
    em_curso->proximo->anterior = em_curso->anterior;   
  }   
  /*free(remov_elemento->dado);   */
  free(remov_elemento);   
  lista->tamanho--;   
  return 0;   
}  

void removerDuplicados(struct ListaDupla * lista)
{
  struct ListaDuplaDado *escolhido, *percorrer;   
  escolhido = lista->inicio;  
  percorrer = lista->inicio; 
  int aux;
  int controle;
  int count = 1;
  while(escolhido != NULL)
  {
    controle = 0;
    aux = escolhido->dado;   
    while(percorrer != NULL)
    {
      if (aux == percorrer->dado)
      {
        controle++;
        if (controle == 2)
        {
          remov(lista, count);
          count = 0;
          break;
        }

      }
      percorrer = percorrer->proximo;
      count++; 
    }
    percorrer = lista->inicio; 
    count = 1;
    escolhido = escolhido->proximo;
    if (count == 0)
    {
      break;
    }
       
  }   
   
}


int main(int argc, char const *argv[])
{

  struct ListaDupla *lista;   
   
  lista = (struct ListaDupla *) malloc(sizeof(struct ListaDupla));   

  inicializacao(lista);   
  insercao_em_uma_lista_vazia(lista, 999);
/*questao 2*/
  inserirOrdenado(lista, 5); 
  inserirOrdenado(lista, 4);
  inserirOrdenado(lista, 6); 
  inserirOrdenado(lista, 13);
  inserirOrdenado(lista, 2);
  inserirOrdenado(lista, 20);
  inserirOrdenado(lista, 3);
  inserirOrdenado(lista, 6); 
  inserirOrdenado(lista, 51); 
  inserirOrdenado(lista, 7);
  inserirOrdenado(lista, 4); 
/*questao 1*/
  inserirMeio(lista, 66);  
  exibe(lista);
/*questao 3*/
  inverter(lista); 

/*questao 4*/
  removerDuplicados(lista);
  exibe(lista);

	return 0;


}

/*****************************************************************************\
################# QUESTÕES ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #

1. Escreva uma função que receba um inteiro e um ponteiro para struct ListaDupla e insira um novo nó meio da lista. Qual a complexidade do seu algoritmo?
	void inserirMeio(struct ListaDupla * lista, int n);
 
2. Considere uma lista duplamente ligada de números inteiros ordenados, escreva uma função que insira um novo número na lista na sua posição correta, mantendo a lista ordenada.
	void inserirOrdenado(struct ListaDupla * lista, int n);
 
3. Escreva uma função que inverta uma lista duplamente ligada de números inteiros.
	void inverter(struct ListaDupla * lista);
 
4. Escreva uma função que receba uma lista duplamente encadeada de números inteiros e elimine os nós que contém números duplicados. Qual a complexidade da sua função?
	void removerDuplicados(struct ListaDupla * lista);
 
5. Escreva uma função que receba uma lista de números inteiros e um número n e crie uma nova lista contendo todos os números maiores que n, removendo­os da lista original. A função deve retornar um ponteiro para a nova lista.
	struct ListaDupla * moverNumerosMaioresQueN(struct ListaDupla *
original, int n); 
 
6. Escreva uma função que ordene uma lista duplamente encadeada. 
	void ordenar(struct ListaDupla * lista); 

\*****************************************************************************/