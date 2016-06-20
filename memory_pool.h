#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define MAX_MEMORY_POOL_NODE 400000
#define SIZE 5381

#define OPT 3
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __MEMORYPOOL {
    entry* array[MAX_MEMORY_POOL_NODE];
    int nodeCounter;
} mempool;


void initialMempool();
entry *mempoolalloc();
void mempoolfree();
entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);
unsigned int hash(char *str);

#endif
