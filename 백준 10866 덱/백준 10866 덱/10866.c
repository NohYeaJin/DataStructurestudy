#include <stdio.h>
#include <string.h>
int start=200;
int end=200;
typedef struct {
	int arr[5000];
	
}deque;
void push_front(deque*d,int data) {

	d->arr[start--] = data;
}

void push_back(deque*d,int data) {
	d->arr[end++] = data;
}
int empty() {
	if (start==end)
		return 1;
	else
		return 0;
}
int front(deque *d) {
	if (empty()) {
		return -1;
	}else
	return d->arr[start];
}
int back(deque* d) {
	if (empty()) {
		return -1;
	}
	else
	return d->arr[end];
}
int pop_front(deque*d) {
	if (empty()) {
		return -1;
	}
	else
	{
		return d->arr[start];
	}
	d->arr[start++];
	free(d);
}
int main() {
	deque* d=(deque*)malloc(sizeof(deque));
	char in[10];

	printf("명령어수 입력:");
	int n;
	scanf_s("%d", &n);
	int i; 
	for (i = 0; i < n; i++) {
		printf("명령어 입력");
		scanf_s("%s", in);
		if (strcmp("push_front", in) == 0) {
			int a;
			scanf_s("%d", &a);
			push_front(d, a);
		}
		else if (strcmp("front", in) == 0) {
			printf("%d", front(d));
		}
		else if (strcmp("empty", in) == 0) {

			printf("%d", empty());
		}
		else if (strcmp("pop_front", in) == 0) {
			printf("%d", pop_front(d));
		}
	}
	return 0;
}
