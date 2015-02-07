#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista_numeros.h"
/*
Desenvolva um programa capaz de manipular mais de uma lista de números/contatos.
O ponteiro para o início da lista deve ser passado como parâmetro a partir do programa principal.
IMPORTANTE: As operações de inserção e remoção devem retornar um ponteiro para o
início da lista, já que uma remoção ou inserção pode mudar o início.

IMPORTANTE: O ponteiro para o inicio da lista está definido no arquivo lista_numeros.c.
Esta decisão limita a quantidade de lista do programa em apenas 1.
Essa decisão foi tomada apenas para fins didáticos, onde o objeto destes exercícios
é entender as operações sobre uma lista (inserção, remoção e busca).
*/
void printMenu() {
	printf("\n");
	printf("*** Programa exemplo de lista ligada de números inteiros ***\n\n");
	printf("    1 - Inserir número no início da lista\n");
	printf("    2 - Inserir número do fim da lista\n");
	printf("    3 - Remover número no início da lista\n");
	printf("    4 - Remover número do fim da lista\n");
	printf("    5 - Buscar um número na lista\n");
	printf("    6 - Mostra a quantidade de elementos existentes na lista\n");
	printf("    7 - Mostra o primeiro número da lista\n");
	printf("    8 - Mostra o último número da lista\n");
	printf("    9 - Lista todos os números\n");
	printf("\n");
	printf(">>> Digite uma opção, ou 0 (zero) para sair: ");

}

int main(int argc, char **argv) {
	int fim, opcao, numero, qtd, result;
	fim = 0;

	inserirAlgunsValoresPraTestar();

	while (!fim) {
		printMenu();
		scanf("%d", &opcao);
		switch (opcao) {

		case 0:
			fim = 1;
			break;

		case 1:
			printf("Digite o número a ser inserido no início da lista: ");
			scanf("%d", &numero);
			assert(inserirInicio(numero) == 1);
			break;

		case 2:
			printf("Digite o número a ser inserido no fim da lista: ");
			scanf("%d", &numero);
			assert(inserirFim(numero) == 1);
			break;

		case 3:
			assert(removeInicio() == listaVazia());
			break;

		case 4:
			assert(removeFim() == listaVazia());
			break;

		case 5:
			printf("Digite uo número a ser buscado na lista: ");
			scanf("%d", &numero);

			if (buscaNumero(numero) == 1) {
				printf("Numero %d está presente na lista\n", numero);
			} else {
				printf("A lista não contém o número %d\n", numero);
			}
			break;

		case 6:
			qtd = quantidade();
			printf("A quantidade de elementos é %d\n", qtd);
			assert(qtd == 4); /* 4 = quantidade de elementos teste */
			break;

		case 7:
			result = primeiro(&numero);
			assert(result == 1);
			assert(numero == 10);
			break;

		case 8:
			result = ultimo(&numero);
			assert(result == 1);
			assert(numero == 40);
			break;

		case 9:
			mostraNumeros();
			break;

		default:
			printf("ATENÇÃO: digite uma opção válida!\n");
			break;
		}

	}

	return EXIT_SUCCESS;
}
