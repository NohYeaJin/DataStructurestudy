#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode {
	int data;
	struct tagNode* Left;
	struct tagNode* Right;
	struct tagNode* Parent;
}Node;

Node* CreateNode(int data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Parent = NULL;
	NewNode->data = data;
	return NewNode;
}

void PostOrderPrintTree(Node* Node) {
	if (Node == NULL)
		return;

	PostOrderPrintTree(Node->Left);
	PostOrderPrintTree(Node->Right);
	printf("%d", Node->data);
}


Node* FindLoc(Node* Parent, int data) {
	Node* insertNode = CreateNode(data);
	Node* CurrentNode = Parent;
	Node* Result = NULL;
	if ((Parent) == NULL) {
		Parent = insertNode;
	}
	else {
		while (CurrentNode != NULL) {
			if (CurrentNode->data > data) {
				Parent->Left = FindLoc(Parent->Left, data);
			}
			else {
				Parent->Right = FindLoc(Parent->Right, data);
			}
		}

	}
	return Parent;
}

int main(void) {

	Node* Tree = NULL;
	int num = 0;
	while (scanf("%d", &num) != EOF) {
		Tree = FindLoc(Tree, num);
	}
	PostOrderPrintTree(Tree);

}