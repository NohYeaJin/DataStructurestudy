#include <stdio.h>
typedef struct node {
	char left;
	char right;
}node;
node nodes[100];
void preorder(unsigned char data) {
	if (data == '.') {
		return;
	}
		printf("%c", data);
		preorder(nodes[data].left);
		preorder(nodes[data].right);
}
void inorder(unsigned char data) {
	if (data == '.') {
		return;
	}
	else {

		inorder(nodes[data].left);
		printf("%c", data);
		inorder(nodes[data].right);
	}
}
void postorder(unsigned char data){
	if (data == '.') {
		return;
	}
	else {
		postorder(nodes[data].left);
		postorder(nodes[data].right);
		printf("%c", data);
	}
}
int main() {
	int N;
	unsigned char d1,d2,d3;
	scanf("%d", &N);
	getchar();

	for (int i = 0; i <N; i++) {
		scanf("%c", &d1);
		scanf(" %c", &d2);
		scanf(" %c", &d3);
		getchar();
		nodes[d1].left = d2;
		nodes[d1].right = d3;

	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");
}
