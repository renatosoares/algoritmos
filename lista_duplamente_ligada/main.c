#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*Cada nó conhece seu sucessor e também seu antecessor*/
struct ListaDuplaLigada{
	int numero;
	struct ListaDuplaLigada *proximo;
	struct ListaDuplaLigada *anterior;
};
struct ListaNumero{
	int num;
	struct ListaNumero *prox;
	
};

struct ListaDuplaLigada *inicio = NULL;
struct ListaNumero *ini = NULL;
/*---------------------------------------------------------------------------*/
/*----------------------------------TRECHO LISTA LIGADA----------------------*/
/*---------------------------------------------------------------------------*/
int inserirIn(int numero) {
	struct ListaNumero *novo;
	int retorno = 1;
	novo = (struct ListaNumero*) malloc(sizeof(struct ListaNumero));
	if (novo == NULL) { /* Verifica se a memória foi alocada */
		retorno = -1;
	} else {
		novo->num = numero;
		novo->prox = ini;
		ini = novo;
	}
	return retorno;
}


void mostraNumeros() {
	struct ListaNumero * atual;
	atual = ini;
	printf("Lista de todos os números cadastrados\n\n");
	while (atual != NULL) {
		printf("   %d\n", atual->num);
		atual = atual->prox;
	}
}

/*---------------------------------------------------------------------------*/
int inserirInicio(int numero)
{
	struct ListaDuplaLigada *novo;
	int retorno = 1;
	novo = (struct ListaDuplaLigada *) malloc(sizeof(struct ListaDuplaLigada));
	if (novo == NULL)
	{
		retorno = -1;
	}
	else
	{
		novo->numero = numero;
		novo->proximo = inicio;
		inicio->anterior = novo;
		novo->anterior = NULL;
		inicio=novo;		
	}


	return retorno;
}


void mostraElementos() {
	struct ListaDuplaLigada * atual;
	atual = inicio;
	printf("Lista de todos os números cadastrados\n\n");
	while (atual != NULL) {
		printf("   %d\n", atual->numero);
		atual = atual->proximo;
	}
}


int main(int argc, char const *argv[])
{
	inserirInicio(10);
	return 0;
}