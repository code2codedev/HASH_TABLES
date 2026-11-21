
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert a value into the hash table
void insert(int key) {
    int index = hashFunction(key);
    int start = index;

    // Linear probing to handle collisions
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}

// Display the hash table
void display() {
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &key);

        insert(key);
    }

    display();

    return 0;
}
