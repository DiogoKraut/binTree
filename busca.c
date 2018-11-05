/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdio.h>
#include <stdlib.h>

#include "binTreeA.h"

int main(int argc, char const *argv[]) {
	char *s = malloc(MAX_TREEB);
	scanf("%s", s);
	int offset = 0;
	tNodeB *root;

	switch(*s) {
		case 'i':
			root = createBTree(s, &offset);
			inOrderPrint(root);
			printf("\n");
			break;
		
	}
	offset = 0;
	free(s);
	return 0;
}
