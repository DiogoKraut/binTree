/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binTreeB.h"

void inOrderPrintBHelper(tNodeB *root) {
	inOrderPrintB(root);
	printf(":%i\n", findSum(root));
}

void inOrderPrintB(tNodeB *root) {
	/* Base da recursao. Caso 1: noh eh nulo */
	if(root == NULL) {
		printf("()");
		return;
	}
	printf("(%i", root->key); // Pre-ordem
	/* Caso 2: se ambos filhos sao nulos, nao olha os filhos */
	if(!root->left && !root->right) {
		printf(")");
		return;
	}
	/* Caso 3: noh tem pelo menos um filho */
	inOrderPrintB(root->left);
	inOrderPrintB(root->right);
	printf(")");
}

tNodeB *init_nodeB(int x) {
	/* Alocacao */
	tNodeB *n = malloc(sizeof(tNodeB));
	if(!n) {
		fprintf(stderr, "Falha ao alocar nohB\n");
		exit(EXIT_FAILURE);
	}
	/* Inicializacao */
	n->key = x;
	n->left = NULL;
	n->right = NULL;

	return n;
}

/* Cria a arvore secundaria noh aa noh recursivamente. *
 * Usa um offset para demarcar o local na string       */
tNodeB *createBTree(char *s, int *offset) {
	int size = strlen(s) - 1; // -1 pois inclui \n
	/* Base da recursao */
	if(size <= *offset)
		return NULL;

	/* Caso 1: noh da forma () eh nulo */
	if(*(s + *offset) == '(' && *(s + (*offset) + 1) == ')') {
		/* Se noh nulo eh filho direito, pula um parentese aa mais */
		if(*(s + (*offset) + 2) == ')')
			*offset += 3; // Pula para o proximo noh
		else // Filho esquerdo
			*offset += 2; // Pula para o proximo noh
		return NULL;
	}

	// Selecionar substring da chave
	char *k;
	char aux[size];
	int num;

	/* Copia de s uma vez que strtok altera a string original   *
	 * Nesta implementacao nao eh nescessario o uso de strtok_r */
	memcpy(aux, s + *offset, size - *offset);

	k = strtok(aux, "(");     // Substring da chave
	*offset += strlen(k) + 1; // proximo noh

	// Converter substring para inteiro
	num = atoi(k);
	// Cria noh novo
	tNodeB *node = init_nodeB(num);

	/* Caso 2: Look-ahead, se ha ')' apos a chave do noh seus filhos sao nulos  */
	if(*(s + *(offset) - 1) == ')')
		return node;

	/* Caso 3: Pelo menos um filho nao eh nulo */
	node->left = createBTree(s, offset);
	node->right = createBTree(s, offset);

	return node;
}

/* Retorna a soma das chaves da arvore secundaria de raiz root */
int findSum(tNodeB *root) {
	int sum = 0;
	/* Base da recursa */
	if(root == NULL)
		return sum;

	sum += root->key;
	return findSum(root->left) + findSum(root->right) + sum;
}

/* Percorre arvore secundaria em pos-ordem para libera-la */
void free_routineB(tNodeB *rootB) {
	if(rootB == NULL)
		return;

	free_routineB(rootB->left);
	free_routineB(rootB->right);
	free(rootB);
}
