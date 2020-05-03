#include <stdio.h>
int cnt = 0;
typedef struct deque {
	int queue[100];
	int front;
	int rear;
}deque;
void init(deque* d) {
	d->front = 0;
	d->rear = 0;
}
void push(deque* d, int num) {
	d->queue[(d->rear)++] = num;
}
void delete(deque* d) {
	return d->queue[(d->front)++];
}
void print(int queue[],int N,int M) {
	int queue2[100];
	deque d;
	int mcnt ;
	init(&d);
	for (int i = 0; i < N; i++) {
		queue2[i] = i;
		push(&d, queue[i]);
	}
	do {
		mcnt = 0;
		int fro = d.front;
		for (int i = d.front; i < d.rear - 1; i++) {
			if (d.queue[d.front] < d.queue[i + 1]) {
				queue2[d.rear] = queue2[d.front];
				queue2[d.front] = -1;
				push(&d, d.queue[d.front]);
				delete(&d);
			}
		}
		if (fro == d.front) {
			queue2[d.front] = -1;
			delete(&d);
			cnt++;

		}
		for (int i = 0; i < d.rear; i++) {
			if (queue2[i] == M) {
				mcnt++;
			}
		}
	} while (mcnt!=0);
}
int main() {
	int test_case;
	int N, M, max;
	int front = 0;
	int queue[100];
	scanf_s("%d", &test_case);
	for (int i = 0; i < test_case; i++) {
		scanf_s("%d %d", &N, &M);
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &queue[j]);
		}
		print(queue, N, M);
		printf("%d\n", cnt);
		cnt = 0;

	}

}