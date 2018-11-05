/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binTreeB.h"

int main(int argc, char const *argv[]) {
	char s[] = "10(8)(30)";
	int offset = 0;
	tNodeB *root = createBTree(s, &offset);
	inOrderPrint(root);
	return 0;
}

void inOrderPrint(tNodeB *root) {
	if(root == NULL)
		return;
	inOrderPrint(root->left);
	printf("%i ", root->key);
	inOrderPrint(root->right);
}

void init_nodeB(tNodeB *n, int x) {
	n->key = x;
	n->left = NULL;
	n->right = NULL;
}

/* Cria a arvore secundaria noh aa noh recursivamente. */
tNodeB *createBTree(char *s, int *offset) {
	tNodeB *node;

	// Base da recursao
	if(strlen(s) <= *offset)
		return NULL;
	// se s[0] == ')' o noh eh nulo
	if(*(s + *offset) == ')') { // noh () eh nulo
		*offset += 2; // Pula para o proximo noh
		return NULL;
	}

	node = malloc(sizeof(tNodeB));
	// Selecionar substring da chave
	char *k;
	char *aux;
	strcpy(aux, s + offset);
	int num;
	k = strtok_r(aux, "()", &aux);

	// Converter substring para inteiro
	num = atoi(k);
	init_nodeB(node, num);

	// Look-ahead, se ha ')' apos a chave do noh seus filhos sao nulos
	if(*(s + *(offset) + 1) == ')') {
		return node;
	}

	node->left = createBTree(s, offset);
	node->right = createBTree(s, offset);

	return node;
}

// Node* stringToTree(string &s, int &loc) {
// 	if(loc>= s.size()) {
// 		return NULL;
// 	}
// 	int len = 0;
// 	while(loc+len < s.size() && (s[loc+len]!='(' && s[loc+len]!=')') ){
// 		len++;
// 	}
// 	string num_string = s.substr(loc,len);
// 	int num = stoi(num_string);
// 	Node* res = newNode(num);
// 	loc+=len;
// 	if ( s[loc]=='(') {
// 		res->left = stringToTree(s,++loc);
// 		loc++;
// 	}
// 	if ( s[loc]=='(') {
// 		res->right = stringToTree(s,++loc);
// 		loc++;
// 	}
// 	return res;
// }

// Node* stringToTreeWrapper(string& s) {
// 	int loc = 0;
// 	return stringToTree(s,loc);
// }
