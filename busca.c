/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdio.h>
#include <stdlib.h>

#include "binTreeA.h"

int main(int argc, char const *argv[]) {
	char *s = malloc(MAX_TREEB);
	int offset;
	tNodeA *rootA = NULL;
	tNodeB *rootB;

	s = "i (10(8)(30))";
	// while(1) {
		// scanf("%s", s);
		offset = 0;
		rootB = createBTree(s + 2, &offset);

		switch(*s) {
			case 'i':
				insertTreeAHelper(rootA, rootB);
				printf("\n");
				break;

			case 'b':
				searchA(rootA, findSum(rootB));
				break;
		}
	// }
	free(s);
	return 0;
}
