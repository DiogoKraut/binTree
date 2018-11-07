/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "binTreeA.h"
#include "binTreeB.h"

tNodeA *init_nodeA(tNodeB *rootB) {
	tNodeA *rootA = malloc(sizeof(tNodeA));
	if(!rootA) {
		fprintf(stderr, "Falha ao alocar rootA\n");
		exit(EXIT_FAILURE);
	}

	rootA->key    = rootB;
	rootA->left   = rootA->right  = NULL;
	rootA->parent = NULL;

	return rootA;
}

tNodeA *insertTreeA(tNodeA *rootA, tNodeB *rootB) {
	/* Base */
	if(rootA == NULL) {
		rootA = init_nodeA(rootB);
		return rootA;
	}

	int sum = findSum(rootB);

	if(findSum(rootA->key) > sum) {
		rootA->left = insertTreeA(rootA->left, rootB);
		rootA->left->parent = rootA;
	}
	else
	if(findSum(rootA->key) < sum) {
		rootA->right = insertTreeA(rootA->right, rootB);
		rootA->right->parent = rootA;
	}
	return rootA;
}


tNodeB *searchA(tNodeA *rootA, tNodeB *rootB) {
	/* Base */
	if(rootA == NULL)
		return NULL;

	inOrderPrintBHelper(rootA->key); // Pre-ordem

	int sum = findSum(rootB);
	/* Encontrou noh */
	if(findSum(rootA->key) == sum)
		return rootA->key;

	/* Nao encountrou, buscar nos filhos */
	if(findSum(rootA->key) > sum)
		return searchA(rootA->left, rootB);

	if(findSum(rootA->key) < sum)
		return searchA(rootA->right, rootB);
	return NULL;
}

void inOrderPrintAHelper(tNodeA *rootA) {
	inOrderPrintA(rootA);
	printf("\n");
}

void inOrderPrintA(tNodeA *rootA) {
	/* Base, noh eh nulo */
	if(rootA == NULL) {
		printf("[]\n");
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

tNodeA *deleteTreeA(tNodeA *rootA, tNodeB *rootB) {
	/* Base */
	if(rootA == NULL)
		return rootA;

	tNodeA *successor;
	int sumB = findSum(rootB);
	int sumA = findSum(rootA->key);

	if(sumB < sumA)
		rootA->left = deleteTreeA(rootA->left, rootB);
	else
		if(sumB > sumA)
			rootA->right = deleteTreeA(rootA->right, rootB);
		else

			/* Encontrou noh. Verificar casos */
			if(rootA->left && rootA->right) { // Caso noh tem ambos filhos
				successor = minA(rootA->right);
				rootA->key = successor->key;
				rootA->right = deleteTreeA(rootA->right, rootA->key);
			} else {
				successor = rootA;
				if(rootA->left == NULL)         // Caso soh tenha filho direito
					rootA = rootA->right;
				else
					if(rootA->right == NULL)      // Caso soh tenha filho esquerdo
						rootA = rootA->left;

				free(successor);
			}
	return rootA;
}

tNodeA *minA(tNodeA *rootA) {
	/* Base */
	if(rootA == NULL)
		return rootA;
	if(rootA->left == NULL)
		return rootA;
	return minA(rootA->left);
}

void free_routineA(tNodeA *rootA) {
	if(rootA == NULL)
		return;

	free_routineB(rootA->key);
	free_routineA(rootA->left);
	free_routineA(rootA->right);
	free(rootA);
}
