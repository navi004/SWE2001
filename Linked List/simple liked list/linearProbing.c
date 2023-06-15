#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int hash(int key) {
    return key % SIZE;  // Simple hash function
}

void insertLinearProbing(int hashTable[], int key) {
    int index = hash(key);  // Compute the initial hash value
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1) {
        // Slot is occupied, probe the next slot
        i++;
        if (i == SIZE) {
            // Hash table is full
            printf("Hash table is full. Cannot insert key.\n");
            return;
        }
    }

    hashTable[(index + i) % SIZE] = key;  // Store the key in the empty slot
}
int search(int hashTable[],int key) {
    int index = hash(key);
    int  i=0;
    while(hashTable[(index+i)%SIZE] != -1) {
        if(hashTable[(index+i)%SIZE] == key) {
            return (index+i)%SIZE;
        }
        i++;
        if(i==SIZE) {
            return -1;
        }
    }
    return -1;
}
void delete(int hashTable[],int key) {
    int index = hash(key);
    int i = 0;
    while(hashTable[(index+i)%SIZE] != -1) {
        if(hashTable[(index+i)%SIZE] == key) {
            hashTable[(index+i)%SIZE] = -1;
        }
        i++;
        if(i == SIZE) {
            printf("Key not found\n");
            return;
        }
    }
}
void displayHashTable(int hashTable[]) {
    printf("Hash Table: \n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("%d \n", hashTable[i]);
        } else {
            printf("Empty \n");
        }
    }
    printf("\n");
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;  // Initialize the hash table with empty slots
    }

    insertLinearProbing(hashTable, 5);
    insertLinearProbing(hashTable, 15);
    insertLinearProbing(hashTable, 25);
    insertLinearProbing(hashTable, 35);
    insertLinearProbing(hashTable, 7);
    insertLinearProbing(hashTable, 17);

    displayHashTable(hashTable);
    int index = search(hashTable,7);
    if(index != -1) {
        printf("Key found at %d",index);
    }
    else {
        printf("Not found");
    }
    delete(hashTable,7);
    displayHashTable(hashTable);

    return 0;
}
