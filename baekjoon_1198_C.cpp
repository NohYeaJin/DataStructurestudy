#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;

Node* CDLL_CreateNode(int NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void CDLL_DestroyNode(Node* Node) {
	Node->PrevNode->NextNode = Node->NextNode;
	Node->NextNode->PrevNode = Node->PrevNode;
	free(Node);
}

void CDLL_AppendNode(Node** Head, Node* NewNode) {
	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;
	}
}

int main(void) {
	int num1;
	int num2;
	int i;
	scanf("%d %d", &num1, &num2);

	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	for (i = 1; i < num1+1; i++) {
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(&List, NewNode);		
	}

	Current = List;
	printf("<");
	while (num1 > 1) {
		for (i = 1; i < num2; i++) {
			Current = Current->NextNode;
		}
		printf("%d, ", Current->Data);
		Current = Current->NextNode;
		CDLL_DestroyNode(Current->PrevNode);
		num1--;
	}
	printf("%d>", Current->Data);
	
}
