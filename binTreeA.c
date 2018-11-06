/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "binTreeA.h"
#include "binTreeB.h"

tNodeA *init_nodeA(tNodeB *rootB) {
	tNodeA *rootA = malloc(sizeof(tNodeA));
	rootA->key    = malloc(sizeof(tNodeB));
	if(!rootA || !rootA->key) {
		fprintf(stderr, "Falha ao alocar rootA\n");
		exit(EXIT_FAILURE);
	}

	memcpy(rootA->key, rootB, sizeof(tNodeB));
	// rootA->key->key   = rootB->key;
	// rootA->key->left  = rootB->left;
	// rootA->key->right = rootB->right;
	rootA->left   = NULL;
	rootA->right  = NULL;
	rootA->parent = NULL;
	free(rootB);
}

void insertTreeAHelper(tNodeA *rootA, tNodeB *rootB) {
	insertTreeA(rootA, rootB);
	inOrderPrintA(rootA);
}

void insertTreeA(tNodeA *rootA, tNodeB *rootB) {
	/* Base */
	if(rootA == NULL)
		rootA = init_nodeA(rootB);
	else
	if(findSum(rootA->key) > findSum(rootB))
		insertTreeA(rootA->left, rootB);
	else
	if(findSum(rootA->key) < findSum(rootB))
		insertTreeA(rootA->right, rootB);
}


void searchA(tNodeA *rootA, int sum) {
	/* Base */
	if(rootA == NULL)
		return;

	inOrderPrintBHelper(rootA->key); // Pre-ordem
	/* Encontrou noh */
	if(findSum(rootA->key) == sum)
		return;

	/* Nao encountrou, buscar nos filhos */
	if(findSum(rootA->key) > sum)
		searchA(rootA->left, sum);
	else if(findSum(rootA->key) < sum)
		searchA(rootA->right, sum);
}

void inOrderPrintA(tNodeA *rootA) {
	/* Base, noh eh nulo */
	if(rootA == NULL) {
		printf("[\n]\n");
		return;
	}
	printf("["); // Pre-ordem
	inOrderPrintBHelper(rootA->key);

	/* Se ambos filhos sao nulos, nao olha os filhos */
	if(!rootA->left && !rootA->right) {
		printf("]\n");
		return;
	}
	/* Se chegou aqui noh tem pelo menos um filho */
	inOrderPrintA(rootA->left);
	inOrderPrintA(rootA->right);
	printf("]\n");
}
