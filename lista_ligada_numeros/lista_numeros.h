#ifndef LISTA_NUMEROS_H_
#define LISTA_NUMEROS_H_

struct ListaNumero {
	int numero;
	struct ListaNumero *proximo;
};

/**
 * retorna -1 se a lista estiver vazia, 1 caso contrário
 * objetivo de facilitar teste de métodos
 */
int listaVazia();

/**
 * Insere alguns valores iniciais na lista
 */
void inserirAlgunsValoresPraTestar();

/*
 * Insere numero no início da lista
 * retorna 1 se a inserção ocorrer sem problemas, -1 caso contrário
 */
int inserirInicio(int numero);

/*
 * Insere numero no fim da lista
 */
int inserirFim(int numero);

/*
 * Remove o número do início da lista
 * retorna 1 se a remoção ocorrer sem problemas, -1 caso contrário
 */
int removeInicio();

/*
 * Remove o número do fim da lista
 * retorna 1 se a remoção ocorrer sem problemas, -1 caso contrário
 */
int removeFim();

/*
 * Busca numero na lista
 * retorna 1 se ele estiver na lista, -1 caso contrário.
 */
int buscaNumero(int numero);

/*
 * Conta quantidade de elementos na lista
 */

int quantidade();

/*
 * Coloca no parâmetro 'int * numero' o primeiro número da lista
 * retorna 1 se o número existir, -1 caso a lista esteja vazia.
 */

int primeiro(int * numero);

/*
 * Coloca no parâmetro 'int * numero' o último número da lista
 * retorna 1 se o número existir, -1 caso a lista esteja vazia.
 */

int ultimo(int * numero);

/*
 * Mostra todos os números da lista, um por linha
 */

void mostraNumeros();

#endif /* LISTA_NUMEROS_H_ */
