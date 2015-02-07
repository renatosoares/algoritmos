#include <stdio.h>
#include <stdlib.h>
#include "lista_numeros.h"

struct ListaNumero *inicio = NULL;

/**
 * retorna -1 se a lista estiver vazia, 1 caso contrário
 * objetivo de facilitar teste de métodos
 */
void inserirAlgunsValoresPraTestar() {
	inserirFim(10);
	inserirFim(20);
	inserirFim(30);
	inserirFim(40);
}

/**
 * Insere alguns valores iniciais na lista
 */
int listaVazia() {
	return inicio == NULL ? -1 : 1;
}

/*
 * Insere numero no início da lista
 * retorna 1 se a inserção ocorrer sem problemas, -1 caso contrário
 */
int inserirInicio(int numero) {
	struct ListaNumero *novo;
	int retorno = 1;
	novo = (struct ListaNumero*) malloc(sizeof(struct ListaNumero));
	if (novo == NULL) { /* Verifica se a memória foi alocada */
		retorno = -1;
	} else {
		novo->numero = numero;
		novo->proximo = inicio;
		inicio = novo;
	}
	return retorno;
}

/*
 * Insere numero no fim da lista
 */
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

/*
 * Remove o número do início da lista
 * retorna 1 se a remoção ocorrer sem problemas, -1 caso contrário
 */
int removeInicio() {
	struct ListaNumero *velho;
	int retorno = 1;
	velho = inicio;
	if (velho == NULL) {
		retorno = -1;
	} else {
		inicio = inicio ->proximo;
		free(velho);
	}
	return retorno;
}

/*
 * Remove o número do fim da lista
 * retorna 1 se a remoção ocorrer sem problemas, -1 caso contrário
 *
 * Complexidade: O(n)
 */
int removeFim() {
	struct ListaNumero * atual;
	int retorno = 1;

	if(inicio != NULL) {
		if(inicio->proximo == NULL) {
			free(inicio);
		}
		else {
			atual = inicio;
			while(atual->proximo->proximo != NULL) {
				atual = atual->proximo;
			}
			free(atual->proximo->proximo);
			atual->proximo = NULL;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

/*
 * Busca numero na lista
 * retorna 1 se ele estiver na lista, -1 caso contrário.
 */
int buscaNumero(int numero) {
	struct ListaNumero * atual;
	int retorno = -1;
	atual = inicio;
	while (atual != NULL) {
		if (atual->numero == numero) {
			retorno = 1;
			break;
		}
		atual = atual->proximo;
	}
	return retorno;
}

/*
 * Conta quantidade de elementos na lista
 *
 * Complexidade: O(n)
 */
int quantidade() {
	int count = 0;
	struct ListaNumero * atual;
	
	if(inicio != NULL) {
		atual = inicio;
		count = 1;
		while(atual->proximo != NULL) {
			count++;
			atual = atual->proximo;
		}
	}

	return count;
}

/*
 * Coloca no parâmetro 'int * numero' o primeiro número da lista
 * retorna 1 se o número existir, -1 caso a lista esteja vazia.
 *
 * Complexidade: O(1)
 */

int primeiro(int * numero) {
	if(inicio == NULL) {
		return -1;
	}

	*numero = inicio->numero;
	return 1;
}

/*
 * Coloca no parâmetro 'int * numero' o último número da lista
 * retorna 1 se o número existir, -1 caso a lista esteja vazia.
 *
 * Complexidade: O(n)
 */

int ultimo(int * numero) {
	if(inicio == NULL) {
		return -1;
	}

	struct ListaNumero * node = inicio;

	while(node->proximo != NULL)
		node = node->proximo;

	*numero = node->numero;

	return 1;
}

/*
 * Mostra todos os números da lista, um por linha
 */

void mostraNumeros() {
	struct ListaNumero * atual;
	atual = inicio;
	printf("Lista de todos os números cadastrados\n\n");
	while (atual != NULL) {
		printf("   %d\n", atual->numero);
		atual = atual->proximo;
	}
}
