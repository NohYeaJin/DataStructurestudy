#include <stdio.h>
#define Max 10
typedef struct hash{
	int arr[Max];
}hash;
int hashCode(int M,int x) {
	return x % M;
}
void insert(int M,hash *h,int num) {
	int address = hashCode(M, num);
	h->arr[address] = num;
}
void search(int num,hash* h,int M) {
	int address = hashCode(M, num);
	if (h->arr[address] == num) {
		printf("%d", 1);
	}
	else {
		printf("%d", 0);
	}
}
void delete(int num, hash* h, int M) {
	int address = hashCode(M, num);
	if (h->arr[address] == num) {
		h->arr[address] = NULL;
	}
	else {
		printf("%d", 0);
	}
}
void print(hash *h) {
	for (int i = 0; i < 10; i++) {
		printf("%d", h->arr[i]);
	}
}
int main() {
	int M;
	scanf_s("%d", &M);
	hash h;
	h.arr[M];
	for (int i = 0; i < M; i++) {
		char s;
		int num;
		scanf_s(" %c", &s);
		switch (s) {
		case 'i' :
			scanf_s("%d", &num);
			int address = hashCode(M,num);
			insert(M,&h,num);
			break;
		case 's':
			scanf_s("%d", &num);
			
			search(num, &h, M);
			break;
		case 'p':
			print(&h);
			break;
		case 'd':
			scanf_s("%d", &num);
			delete(num, &h, M);

		case 'e':
			return;
		}
	}
}