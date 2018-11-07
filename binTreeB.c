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
	/* Base, noh eh nulo */
	if(root == NULL) {
		printf("()");
		return;
	}
	printf("(%i", root->key); // Pre-ordem
	/* Se ambos filhos sao nulos, nao olha os filhos */
	if(!root->left && !root->right) {
		printf(")");
		return;
	}
	/* Se chegou aqui noh tem pelo menos um filho */
	inOrderPrintB(root->left);
	inOrderPrintB(root->right);
	printf(")");
}

tNodeB *init_nodeB(int x) {
	tNodeB *n = malloc(sizeof(tNodeB));
	if(!n) {
		fprintf(stderr, "Falha ao alocar nohB\n");
		exit(EXIT_FAILURE);
	}

	n->key = x;
	n->left = NULL;
	n->right = NULL;

	return n;
}

/* Cria a arvore secundaria noh aa noh recursivamente. *
 * Usa um offset para demarcar o local na string       */
tNodeB *createBTree(char *s, int *offset) {
	int size = strlen(s) - 1; // -1 pois inclui \n
	// Base da recursao
	if(size <= *offset)
		return NULL;

	if(*(s + *offset) == '(' && *(s + (*offset) + 1) == ')') { // noh () eh nulo
		*offset += 2; // Pula para o proximo noh
		return NULL;
	}

	// Selecionar substring da chave
	char *k;
	char aux[size];
	int num;
	strcpy(aux, s + *offset); // Copia de s

	k = strtok(aux, "(");
	*offset += strlen(k) + 1;

	// Converter substring para inteiro
	num = atoi(k);
	// Cria noh novo
	tNodeB *node = init_nodeB(num);

	/* Look-ahead, se ha ')' apos a chave do noh seus filhos sao nulos  */
	if(*(s + *(offset) - 1) == ')')
		return node;

	node->left = createBTree(s, offset);
	node->right = createBTree(s, offset);

	return node;
}

int findSum(tNodeB *root) {
	int sum = 0;
	if(root == NULL)
		return sum;
	sum += root->key;
	return findSum(root->left) + findSum(root->right) + sum;
}

void free_routineB(tNodeB *rootB) {
	if(rootB == NULL)
		return;

	free_routineB(rootB->left);
	free_routineB(rootB->right);
	free(rootB);
}
