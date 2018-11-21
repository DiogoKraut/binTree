/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdio.h>
#include <stdlib.h>

#include "binTreeA.h"

int main(int argc, char const *argv[]) {
	char s[MAX_TREEB];
	int offset;
	tNodeA *rootA = NULL;
	tNodeB *rootB = NULL;
	tNodeA *tmp;

	while(1) {
		fgets(s, MAX_TREEB, stdin); // Le um comando
		offset = 0;
		rootB = createBTree(s + 2, &offset); // Pula o comando e o espaco em branco

		switch(*s) {
			case 'i':
				rootA = insertTreeA(rootA, rootB);
				inOrderPrintA(rootA);
				break;

			case 'b':
				searchA(rootA, rootB);
				break;

			case 'r':
					tmp = deleteTreeA(&rootA, rootB);
					if(tmp != NULL) { // tmp == NULL significa que noh nao existia
						free_routineB(tmp->key);
						free(tmp);
						inOrderPrintA(rootA);
					}
				break;
		}
		printf("\n");
	}

	/* Liberar arvores primarias e secundarias */
	free_routineA(rootA);
	return 0;
}
