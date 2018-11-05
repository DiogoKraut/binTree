/* DIOGO PARIS KRAUT - GRR20166365 */

#define MAX_TREEB 30
typedef struct sNodeB {
	int key;
	struct sNodeB*left, *right;
} tNodeB;

tNodeB *createBTree(char *s, int *offset);
void init_nodeB(tNodeB *n, int x);
void inOrderPrint(tNodeB *root);
