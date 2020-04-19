#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
	int key = 0;
	int value;
}Node;

typedef struct tagHashTable {
	int TableSize;
	 Node* Table;
}HashTable;

HashTable* CreateHashTable(int TableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (Node*)malloc(sizeof(Node)*TableSize);
	HT->TableSize = TableSize;

	return HT;
}

int Hash(int key, int Tablesize) {
	return key % Tablesize;
}

void set(HashTable* HT, int key) {
	int Address = Hash(key, HT->TableSize);
	HT->Table[Address].key = key;
	
}

int Delete(HashTable* HT, int key) {
	int Address = Hash(key, HT->TableSize);
	if ((HT->Table[Address].key) == NULL) {
		return 0;
	}
	else {
		(HT->Table[Address].key) = NULL;
		return Address;
	}
}

void print(HashTable* HT) {
	for (int i = 0; i < HT->TableSize; i++) {
		if ((HT->Table[i].key) != NULL) {
			printf("%d ", HT->Table[i].key);
		}
	}
}

int Get(HashTable* HT, int key) {
	int Address = Hash(key, HT->TableSize);
	return Address;
}

int search(HashTable* HT, int key) {
	int Address = Hash(key, HT->TableSize);
	if ((HT->Table[Address].key) == NULL) {
		return 0;
	}
	else {
		return Address;
	}
}

int main(void) {
	char dir[100];
	int num;
	int result;
	HashTable* HT = CreateHashTable(10);
	for (int i = 0; i < 10; i++) {
		HT->Table[i].key = NULL;
	}
	for (int i = 0; i < 13; i++) {
		printf("\n");
		scanf("%s", &dir);
		if (strcmp(dir, "i") == 0) {
			scanf("%d", &num);
			set(HT, num);
		}
		if (strcmp(dir, "s") == 0) {
			scanf("%d", &num);
			result = search(HT, num);
			printf("%d", result);
		}
		if (strcmp(dir, "d") == 0) {
			scanf("%d", &num);
			result = Delete(HT, num);
			printf("%d", result);
		}
		if (strcmp(dir, "p") == 0) {
			print(HT);
		}
	}

}
