#include <stdio.h>
#define SIZE 10

int hash_table[SIZE];

void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hash_table[i] = -1;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insertKey(int key) {
    int index = hashFunction(key);
    int i=0;
    while(hash_table[(index+i*i)%SIZE] != -1) {
        i++;

        if(i>=SIZE) {
            printf("Table is Full");
            return;
        }
    }
    hash_table[(index+i*i)%SIZE] = key;
}
void deleteKey(int key) {
    int index = hashFunction(key);
    int i = 0;
    
    while (hash_table[(index+i*i)%SIZE] != -1) {
        if (hash_table[(index+i*i)%SIZE] == key) {
            hash_table[(index+i*i)%SIZE] = -1;  // Mark as deleted
            printf("Key %d deleted successfully\n", key);
            return;
        }
         // Quadratic probing
        i++;
    }
    
    printf("Key %d not found in the hash table\n", key);
}

void displayHashTable() {
    printf("Hash Table: \n");
    for (int i = 0; i < SIZE; i++) {
        if(hash_table[i] != -1)
            printf("%d \n", hash_table[i]);
        else {
            printf("Empty \n");
        }
    }
    printf("\n");
}
int search(int key) {
    int index = hashFunction(key);
    int  i=0;
    while(hash_table[(index+i*i)%SIZE] != -1) {
        if(hash_table[(index+i*i)%SIZE] == key) {
            return (index+i*i)%SIZE;
        }
        i++;
        if(i >= SIZE) {
            return -1;
        }
    }
    return -1;
}

int main() {
    initializeHashTable();
    
    insertKey(5);
    insertKey(11);
    insertKey(21);
    insertKey(1);
    insertKey(14);
    insertKey(6);
    insertKey(7);
    insertKey(8);
    insertKey(9);
    
    printf("Before deletion:\n");
    displayHashTable();
    
    deleteKey(21);
    
    printf("After deletion of key 25:\n");
    displayHashTable();
    int index = search(9);
    if(index != -1) {
        printf("Key found at %d",index);
    }
    else {
        printf("Key not found\n");
    }
    
    return 0;
}
