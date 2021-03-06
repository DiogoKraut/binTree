/* DIOGO PARIS KRAUT - GRR20166365 */
#ifndef __A__
#define __A__

#include "binTreeB.h"

typedef struct sNodeA {
	tNodeB *key;
	struct sNodeA *left, *right, *parent;
} tNodeA;

tNodeA *init_nodeA(tNodeB *rootB);
tNodeA *insertTreeA(tNodeA *rootA, tNodeB *rootB);
tNodeB *searchA(tNodeA *rootA, tNodeB *rootB);
void inOrderPrintA(tNodeA *rootA);
void free_routineA(tNodeA *rootA);
void transplantA(tNodeA **u, tNodeA **v);
tNodeA *deleteTreeA(tNodeA **rootA, tNodeB *rootB);
tNodeA *minA(tNodeA *rootA);

#endif
