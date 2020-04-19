#include <stdio.h>
typedef struct node {
	char left;
	char right;
}node;
node nodes[100];
void preorder(char data) {
	if (data == '.') {
		return;
	}
	else {
		printf(" %c", data);
		preorder(nodes[data].left);
		preorder(nodes[data].right);
		
	}
}
void inorder(char data) {
	if (data == '.') {
		return;
	}
	else {

		inorder(nodes[data].left);
		printf(" %c", data);
		inorder(nodes[data].right);
	}
}
void postorder(char data){
	if (data == '.') {
		return;
	}
	else {
		postorder(nodes[data].left);
		postorder(nodes[data].right);
		printf(" %c", data);
	}
}
int main() {
	int N;
	char d1,d2,d3;
	scanf_s("%d", &N);


	for (int i = 0; i <N; i++) {
		scanf_s(" %c", &d1,1);
		scanf_s(" %c", &d2,1);
		scanf_s(" %c", &d3,1);
		nodes[d1].left = d2;
		nodes[d1].right = d3;

	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');

	
}