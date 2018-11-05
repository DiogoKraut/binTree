/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binTreeB.h"

int main(int argc, char const *argv[]) {
	char *s = malloc(MAX_TREEB);
	scanf("%s", s);
	int offset = 0;
	tNodeB *root = createBTree(s, &offset);
	inOrderPrint(root);
	printf("\n");
	return 0;
}

void inOrderPrint(tNodeB *root) {
	if(root == NULL)
		return;
	inOrderPrint(root->left);
	printf("%i ", root->key);
	inOrderPrint(root->right);
}

void init_nodeB(tNodeB *n, int x) {
	n->key = x;
	n->left = NULL;
	n->right = NULL;
}

/* Cria a arvore secundaria noh aa noh recursivamente. *
 * Usa um offset para demarcar o local na string       */
tNodeB *createBTree(char *s, int *offset) {
	int size = strlen(s);
	// Base da recursao
	if(size <= *offset)
		return NULL;

	if(*(s + *offset) == '(' && *(s + (*offset) + 1) == ')') { // noh () eh nulo
		*offset += 2; // Pula para o proximo noh
		return NULL;
	}

	// Cria noh novo
	tNodeB *node;
	node = malloc(sizeof(tNodeB));

	// Selecionar substring da chave
	char *k;
	char aux[size];
	int num;
	strcpy(aux, s + *offset); // Copia de s
	
	k = strtok(aux, "(");
	*offset += strlen(k) + 1;

	// Converter substring para inteiro
	num = atoi(k);
	init_nodeB(node, num);

	/* Look-ahead, se ha ')' apos a chave do noh seus filhos sao nulos  *
	 * Nesse caso, pela natureza de strtok, ')' sempre esta no fim de k *
	 * portanto subtraimos 1 de s                                       */
	if(*(s + *(offset) - 1) == ')')
		return node;

	node->left = createBTree(s, offset);
	node->right = createBTree(s, offset);

	return node;
}