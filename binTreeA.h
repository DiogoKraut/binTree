/* DIOGO PARIS KRAUT - GRR20166365 */

#include "binTreeB.h"

typedef struct sNodeA {
	tNodeB *key;
	struct sNodeA *left, *right, *parent;
} tNodeA;