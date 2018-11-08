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
	rootA->left   = NULL;
	rootA->right  = NULL;
	rootA->parent = NULL;

	return rootA;
}

tNodeA *insertTreeA(tNodeA *rootA, tNodeB *rootB) {
	/* Base da recursao */
	if(rootA == NULL) {
		rootA = init_nodeA(rootB);
		return rootA;
	}

	int sum = findSum(rootB);

	if(findSum(rootA->key) > sum) {
		rootA->left = insertTreeA(rootA->left, rootB);
		rootA->left->parent = rootA;
	}
	else if(findSum(rootA->key) < sum) {
		rootA->right = insertTreeA(rootA->right, rootB);
		rootA->right->parent = rootA;
	}
	return rootA;
}


tNodeB *searchA(tNodeA *rootA, tNodeB *rootB) {
	/* Base da recursao*/
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
	/* Noh nao existe */
	return NULL;
}

void inOrderPrintA(tNodeA *rootA) {
	/* Base da recursa. Caso 1: Noh eh nulo */
	if(rootA == NULL) {
		printf("[]\n");
		return;
	}

	printf("[");
	inOrderPrintBHelper(rootA->key); // Pre-ordem

	/* Caso 2: Se ambos filhos sao nulos, nao olha os filhos */
	if(!rootA->left && !rootA->right) {
		printf("]\n");
		return;
	}
	/* Caso 3: Noh tem pelo menos um filho */
	inOrderPrintA(rootA->left);
	inOrderPrintA(rootA->right);
	printf("]\n");
}

/* Troca a sub-arvore *u pela sub-arvore *v, e altera os ponteiros para pais *
 * de acordo. Algoritimo "TRANSPLANT" do Cormen                              */
void transplantA(tNodeA **u, tNodeA **v) {
	if((*u)->parent == NULL) { // Caso raiz
		(*u) = (*v);
	} else
		if((*u) == (*u)->parent->left) // u eh filho esq
			(*u)->parent->left = (*v);
		else                           // u eh filho dir
			(*u)->parent->right = (*v);

	if((*v) != NULL)
		(*v)->parent = (*u)->parent;
}

tNodeA *deleteTreeA(tNodeA **rootA, tNodeB *rootB) {
	/* Base */
	if(*rootA == NULL)
		return NULL;

	tNodeA *successor, *tmp;
	int sumA = findSum((*rootA)->key);
	int sumB = findSum(rootB);

	if(sumB < sumA) {
		tmp = deleteTreeA(&(*rootA)->left, rootB);
	} else {
		if(sumB > sumA) {
			tmp = deleteTreeA(&(*rootA)->right, rootB);
		} else {
			/* Encontrou noh. Verificar casos. (TREE-DELETE do Cormen) */
			tmp = *rootA;
			if((*rootA)->left == NULL)       // Caso 1: Filho esquerdo nulo
				transplantA(rootA, &(*rootA)->right);
			else if((*rootA)->right == NULL) // Caso 2:tem filho esq mas nao filho dir
				transplantA(rootA, &(*rootA)->left);
			else {                           // Caso 3: Tem ambos os filhos
				/* Sucessor entra no lugar do noh a ser removido */
				successor = minA((*rootA)->right);
				/* Se o pai do sucessor nao for o noh a ser removido, usar o filho *
				 * direito do sucessor                                             */
				if(successor->parent != *rootA) {
					transplantA(&successor, &successor->right);
					successor->right = (*rootA)->right;
					successor->right->parent = successor;
				}
				transplantA(rootA, &successor);
				successor->left = (*rootA)->left;
				successor->left->parent = successor;
			}
		}
	}
	return tmp;
}

tNodeA *minA(tNodeA *rootA) {
	/* Base da recursao */
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
