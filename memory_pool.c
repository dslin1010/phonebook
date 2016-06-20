#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory_pool.h"

#define MAX_MEMORY_POOL_NODE 400000
/* FILL YOUR OWN IMPLEMENTATION HERE! */

mempool allocNode;

unsigned int num=0;

void initialMempool()
{

    unsigned int index;
    for(index=0; index < MAX_MEMORY_POOL_NODE ; index++) {
        allocNode.array[index]=(entry *)malloc(sizeof(entry));
        allocNode.nodeCounter++;
    }
}

entry *mempoolalloc()
{
    if(allocNode.array[num]==NULL) {
        printf("there's no free entry in pool \n");
        return NULL;
    } else
        allocNode.nodeCounter--;
    return allocNode.array[num++];
}

void mempoolfree()
{
    unsigned int index;
    for(index=0; index<MAX_MEMORY_POOL_NODE; index++)
        free(allocNode.array[index]) ;
}

entry *findName(char lastName[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext=mempoolalloc();
    e=e->pNext;
    memcpy(e->lastName,lastName,strlen(lastName)+1);
    e->pNext=NULL;
    return e;
}

unsigned int hash(char *str)
{

    unsigned int hash=0;
    while(*str) {
        hash=((hash<<5)+hash)+(*str++);
    }
    return (hash % SIZE);
}
