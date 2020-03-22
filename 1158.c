#include <stdio.h>

typedef struct {
	int data;
	
	struct Node* next;
}Node;
typedef struct {
	Node* head;
	Node* cur;
}linked_list;
void init(Node*node) {

	node->next = NULL;
	node->data = 0;
	
}
void num(linked_list*l,int N,int K) {
	l->cur = NULL;
	l->head = NULL;
	for (int i = 1; i < N+1; i++) {
		Node* new_node = (Node*)malloc(sizeof(Node));
		init(new_node);
		new_node->data = i;

		if (l->head == NULL) {
			l->head = new_node;
			return;
		}
		
		if (i==K) {
			
		
			do{
				if (l->cur->data==i) {
					printf("%d", l->cur->data);
					free(l->cur);
					if ((i + K) > N) {
						(i + K) - N;
					}
					else
						i += K;
				}else
				l->cur = l->cur->next;
				
			
			} while (l->cur == NULL);
			

		
		}

	}

}

int main() {
	linked_list l;
	int N, K;
	scanf_s("%d %d", &N, &K);
	num(&l, N, K);

	

}