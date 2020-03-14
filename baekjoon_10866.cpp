#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode{
	int Data;
} Node;

typedef struct tagdeque {
	int size;
	int Front;
	int Rear;

	Node* Nodes;
} deque;

void CreateQueue(deque** Queue, int size)
{
	(*Queue) = (deque*)malloc(sizeof(deque));

	(*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(size+1));

	(*Queue)->size = size;

	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;

}

void DestroyQueue(deque* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

void pushBack(deque* Queue, int Data)
{
	int position = 0;
	position = Queue->Rear;
	Queue->Rear++;
	Queue->Nodes[position].Data = Data;
}

void pushFront(deque* Queue, int Data)
{
	int i;
	int position = Queue->Front;

	if (Queue->Rear == 0)
	{
		Queue->Nodes[position].Data = Data;
	}
	else
	{
		for(i=Queue->Rear;i>=position+1;i--)
		{
			Queue->Nodes[i].Data = Queue->Nodes[i-1].Data;
		}
		Queue->Nodes[position].Data = Data;
	}
	Queue->Rear++;
}

void isEmpty(deque* Queue)
{
	printf("%d\n",Queue->Front == Queue->Rear);
}

void GetSize(deque* Queue)
{
	printf("%d\n", Queue->Rear - Queue->Front);
}

void popFront(deque* Queue)
{
	int position = Queue->Front;
	if (Queue->Front == Queue->Rear)
	{
		printf("-1\n");
	}
	else
	{
		Queue->Front++;
		printf("%d\n", Queue->Nodes[position].Data);
	}
}

void popBack(deque* Queue)
{
	int position = Queue->Rear;
	if (Queue->Front == Queue->Rear)
	{
		printf("-1\n");
	}
	else
	{
		Queue->Rear--;
		printf("%d\n", Queue->Nodes[position-1].Data);
	}
}

void Front(deque* Queue)
{	
	int position = Queue->Front;
	if (Queue->Front == Queue->Rear)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", Queue->Nodes[position].Data);
	}
}

void Back(deque* Queue)
{
	int position = Queue->Rear;
	if (Queue->Front == Queue->Rear)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", Queue->Nodes[position-1].Data);
	}
}

int main(void)
{
	int i = 10000;
	int cmd_num = 0;
	int num = 0;
	deque* Queue;
	char dir[100];
	CreateQueue(&Queue, i);
	scanf("%d", &cmd_num);
	for (i = 0; i < cmd_num; i++)
	{
		scanf("%s", &dir);
		if (strcmp(dir, "push_front") == 0)
		{
			scanf("%d", &num);
			pushFront(Queue, num);
		}
		else if (strcmp(dir, "push_back") == 0)
		{
			scanf("%d", &num);
			pushBack(Queue, num);
		}
		else if (strcmp(dir, "pop_front") == 0)
		{
			popFront(Queue);
		}
		else if (strcmp(dir, "pop_back") == 0)
		{
			popBack(Queue);
		}
		else if (strcmp(dir, "size") == 0)
		{
			GetSize(Queue);
		}
		else if (strcmp(dir, "empty") == 0)
		{
			isEmpty(Queue);
		}
		else if (strcmp(dir, "front") == 0)
		{
			Front(Queue);
		}
		else if (strcmp(dir, "back") == 0)
		{
			Back(Queue);
		}

	}
	return 0;

}



