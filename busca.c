/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdio.h>
#include <stdlib.h>

#include "binTreeA.h"

int main(int argc, char const *argv[]) {
	char *s = malloc(MAX_TREEB);
	int offset;
	tNodeA *rootA = NULL;
	tNodeB *rootB;

	while(1) {
		fgets(s, MAX_TREEB, stdin);
		offset = 0;
		rootB = createBTree(s + 2, &offset);

		switch(*s) {
			case 'i':
				rootA = insertTreeA(rootA, rootB);
				inOrderPrintA(rootA);
				break;

			case 'b':
				searchA(rootA, rootB);
				inOrderPrintA(rootA);
				break;

			case 'r':
				if(searchA(rootA, rootB) != NULL) {
					deleteTreeA(rootA, rootB);
					inOrderPrintA(rootA);
				}
				break;
		}
		printf("\n");
	}

	/* Liberar arvores primarias e secundarias */
	free(s);
	free_routineA(rootA);
	return 0;
}
