/* DIOGO PARIS KRAUT - GRR20166365 */
#ifndef __A__
#define __A__

#include "binTreeB.h"

typedef struct sNodeA {
	tNodeB *key;
	struct sNodeA *left, *right, *parent;
} tNodeA;

tNodeA *init_nodeA(tNodeB *rootB);
void insertTreeAHelper(tNodeA *rootA, tNodeB *rootB);
void insertTreeA(tNodeA *rootA, tNodeB *rootB);
void searchA(tNodeA *rootA, int sum);
void inOrderPrintA(tNodeA *rootA);

#endif
