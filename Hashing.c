#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  


int hashTable[TABLE_SIZE];


void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}


int hashFunction(int key) {
    return key % TABLE_SIZE;
}


void insert(int key) {
    int index = hashFunction(key);

    
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE; 
    }

    hashTable[index] = key;   
    printf("Inserted key %d at index %d\n", key, index);
}


int search(int key) {
    int index = hashFunction(key);
    int startIndex = index;  
   
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;  
        }
        index = (index + 1) % TABLE_SIZE;

        
        if (index == startIndex) {
            break;
        }
    }
    return -1; 
}


void delete(int key) {
    int index = search(key);
    if (index != -1) {
        hashTable[index] = -1;  
        printf("Deleted key %d from index %d\n", key, index);
    } else {
        printf("Key %d not found for deletion\n", key);
    }
}


void displayHashTable() {
    printf("Hash Table: \n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
   
    initializeHashTable();

    
    insert(12);
    insert(22);
    insert(32);
    insert(42);

   
    displayHashTable();


    int keyToSearch = 22;
    int result = search(keyToSearch);
    if (result != -1) {
        printf("Key %d found at index %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found\n", keyToSearch);
    }

    
    delete(22);
    displayHashTable();

    return 0;
}
