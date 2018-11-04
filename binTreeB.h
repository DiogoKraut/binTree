/* DIOGO PARIS KRAUT - GRR20166365 */

typedef struct sNodeB {
	int key;
	struct sNodeB*left, *right;
} tNodeB;

tNodeB *createBTree(char *s);
void printBInOrder(tNodeB *root);
void init_nodeB(tNodeB *n, int x);
