#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
	int Data;
	int importance;
	struct tagNode* NextNode;
} Node;

typedef struct tagQueue {
	Node* Front;
	Node* Rear;
}Queue;

void init(tagQueue* Queue) {
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

void Enqueue(tagQueue* Queue, int Data,int importance)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->NextNode = NULL;
	NewNode->Data = Data;
	NewNode->importance = importance;

	if (Queue->Front == NULL||Queue->Rear==NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		printf("dsd");
	}
	else {
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}
}

Node* Dequeue(tagQueue* Queue)
{
	Node* delNode = Queue->Front;
	Queue->Front = Queue->Front->NextNode;
	return delNode;
}

int Printer(tagQueue** Queue,int findnum,int papernum) {
	int order = 0;
	while ((*Queue)->Front != NULL) {
		int max = 0;
		Node* CurrentNode = (*Queue)->Front;
		int num = (*Queue)->Front->importance;
		printf("%d lalal", num);
		for (int i = 0; i < papernum; i++) {
			if(CurrentNode->importance > max)
				max = CurrentNode->importance;
			if (i != papernum - 1) {
				CurrentNode = CurrentNode->NextNode;
			}
		}
		CurrentNode = (*Queue)->Front;
		while (CurrentNode->importance != max) {
			Node* delNode = Dequeue(*Queue);
			Enqueue((*Queue), delNode->Data, delNode->importance);
			CurrentNode = CurrentNode->NextNode;
		}
		order = order + 1;
		Dequeue(*Queue);
		if (CurrentNode->Data == findnum)
			return order;
	}
}

int main(void)
{
	int buffer = 100;//큐의 사이즈
	int num; //테스트 케이스 수
	int papernum; //문서 수
	int findnum; //궁금한 문서번호
	int importance; //중요도
	int order; //순서번호
	int max = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		tagQueue* NewQueue;
		NewQueue = (Queue*)malloc(sizeof(Queue));
		init(NewQueue);
		scanf("%d %d", &papernum, &findnum);
		for (int j = 0; j < papernum; j++) {
			scanf("%d", &importance);
			Enqueue(NewQueue, j, importance);
		}
		order = Printer((&NewQueue),findnum,papernum);
		printf("%d", order);
		free(NewQueue);
	}

}