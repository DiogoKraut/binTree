/* DIOGO PARIS KRAUT - GRR20166365 */
#ifndef __B__
#define __B__

#define MAX_TREEB 30

typedef struct sNodeB {
	int key;
	struct sNodeB *left, *right;
} tNodeB;

tNodeB *createBTree(char *s, int *offset);
tNodeB *init_nodeB(int x);
void inOrderPrintB(tNodeB *root);
void inOrderPrintBHelper(tNodeB *root);
int findSum(tNodeB *root);

#endif
