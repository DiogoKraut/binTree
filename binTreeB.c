/* DIOGO PARIS KRAUT - GRR20166365 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binTreeB.h"

int main(int argc, char const *argv[]) {
	char s[] = "1(12()(13()()))";
	tNodeB *root = createBTree(s);
	return 0;
}

void init_nodeB(tNodeB *n, int x) {
	n->key = x;
	n->left = NULL;
	n->right = NULL;
}

/* Cria a arvore secundaria noh aa noh recursivamente. */
tNodeB *createBTree(char *s) {
	int size = 0;
	tNodeB *node;

	// Base da recursao
	if(strlen(s) <= 0)
		return NULL;
	// se s[0] == ')' o noh eh nulo
	if(*s == ')') {
		node = NULL;
		s++;
	} else {
		node = malloc(sizeof(tNodeB));
		// Selecionar substring da chave
		char *k = malloc(sizeof(char)*20);
		int num;
		k = strtok_r(s, "()", &s);

		// Converter substring para inteiro
		num = atoi(k);
		init_nodeB(node, num);
	}
	node->left = createBTree(s);
	node->right = createBTree(s);

	return node;
}

Node* stringToTree(string &s, int &loc) {
if(loc>= s.size()) {
	return NULL;
}
int len = 0;
while(loc+len < s.size() && (s[loc+len]!='(' && s[loc+len]!=')') ){
	len++;
}
string num_string = s.substr(loc,len);
int num = stoi(num_string);
Node* res = newNode(num);
loc+=len;
if ( s[loc]=='(') {
	res->left = stringToTree(s,++loc);
	loc++;
}
if ( s[loc]=='(') {
	res->right = stringToTree(s,++loc);
	loc++;
}
return res;
}

Node* stringToTreeWrapper(string& s) {
int loc = 0;
return stringToTree(s,loc);
}
