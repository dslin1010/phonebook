#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include IMPL

#define DICT_FILE "./dictionary/words.txt"

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    int i = 0;
    char line[MAX_LAST_NAME_SIZE];
    struct timespec start, end;
    double cpu_time1, cpu_time2;

    /* check file opening */
    fp = fopen(DICT_FILE, "r");
    if (fp == NULL) {
        printf("cannot open the file\n");
        return -1;
    }
    <<<<<<< HEAD
#if OPT==3
    initialMempool();
#endif

#if OPT==2 || OPT==3

#define SIZE 5381
    entry *hash_table[SIZE]= {NULL};
    entry *e[SIZE]= {NULL};
#else
    =======

        >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
        /* build the entry */
        entry *pHead, *e;
    pHead = (entry *) malloc(sizeof(entry));
    e = pHead;
    e->pNext = NULL;

#if defined(__GNUC__)
    <<<<<<< HEAD
#if OPT==2 || OPT==3
    __builtin___clear_cache((char *) hash_table, (char *) hash_table + SIZE*sizeof(entry));
#else
    =======
        >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
        __builtin___clear_cache((char *) pHead, (char *) pHead + sizeof(entry));
#endif
    clock_gettime(CLOCK_REALTIME, &start);
    while (fgets(line, sizeof(line), fp)) {
        while (line[i] != '\0')
            i++;
        line[i - 1] = '\0';
        <<<<<<< HEAD
        i=0;
#if OPT==2 || OPT==3
        unsigned int key=hash(line);
        if(hash_table[key]==NULL) {
#if OPT==3
            hash_table[key]=mempoolalloc();
#else
            hash_table[key]=(entry *)malloc(sizeof(entry));
#endif
            e[key] = hash_table[key];
            memcpy(e[key]->lastName,line,strlen(line)+1);
            e[key]->pNext=NULL;
        } else {
            e[key] = append(line,e[key]);
        }
#else
        =======
            i = 0;
        >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
        e = append(line, e);
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);

    <<<<<<< HEAD
    /*#if OPT==2
        FILE *fkey ;
        fp = fopen(DICT_FILE, "r");
        fkey = fopen("key.txt", "a");
        while (fgets(line, sizeof(line), fp)) {
            while (line[i] != '\0')
                i++;
            line[i - 1] = '\0';
            i=0;
            unsigned int key=hash(line);
            fprintf(fkey, "%d \n", key);
        }
        fclose(fkey);
#endif        */
        =======
            >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
            /* close file as soon as possible */
            fclose(fp);

        e = pHead;

        /* the givn last name to find */
        char input[MAX_LAST_NAME_SIZE] = "zyxel";
        <<<<<<< HEAD
#if OPT==2 || OPT==3
        unsigned int key=hash(input);
        e[key]=hash_table[key];
#else
        =======
            >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
            e = pHead;

        <<<<<<< HEAD
#if OPT==2 || OPT==3
        assert(findName(input, e[key]) &&
               "Did you implement findName() in " IMPL "?");
        assert(0 == strcmp(findName(input, e[key])->lastName, "zyxel"));
#else
        =======
            >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
            assert(findName(input, e) &&
                   "Did you implement findName() in " IMPL "?");
        assert(0 == strcmp(findName(input, e)->lastName, "zyxel"));

#if defined(__GNUC__)
        <<<<<<< HEAD
#if OPT==2 || OPT==3
        __builtin___clear_cache((char *) hash_table, (char *) hash_table + SIZE*sizeof(entry));
#else
        =======
            >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
            __builtin___clear_cache((char *) pHead, (char *) pHead + sizeof(entry));
#endif
        /* compute the execution time */
        clock_gettime(CLOCK_REALTIME, &start);
        <<<<<<< HEAD
#if OPT==2 || OPT==3
        findName(input, e[key]);
#else
        =======
            >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
            findName(input, e);
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time2 = diff_in_second(start, end);

        FILE *output;
        <<<<<<< HEAD
#if OPT==3
        output = fopen("mempool.txt", "a");
#elif OPT==2
        output = fopen("hash.txt", "a");
#elif OPT==1
        =======
#if defined(OPT)
            >>>>>>> parent of 418abfb... add hash funtion and shrink entry size
            output = fopen("opt.txt", "a");
#else
            output = fopen("orig.txt", "a");
#endif
        printf("size of entry : %lu bytes\n", sizeof(entry));
        fprintf(output, "append() findName() %lf %lf\n", cpu_time1, cpu_time2);
        fclose(output);

        printf("execution time of append() : %lf sec\n", cpu_time1);
        <<<<<<< HEAD
        printf("execution time of findName() : %.10lf sec\n", cpu_time2);
#if OPT==3
        mempoolfree();
#elif OPT==2
        entry *tmp,*release;
        for(i=0; i<SIZE; i++) {
            tmp=hash_table[i];
            while(tmp) {
                release=tmp;
                tmp=tmp->pNext;
                free(release);
            }
        }
#else
        e=pHead;
        while(e) {
            pHead=e;
            e=e->pNext;
            free(pHead);
        }
#endif
        =======
            printf("execution time of findName() : %lf sec\n", cpu_time2);

        if (pHead->pNext) free(pHead->pNext);
        free(pHead);
        >>>>>>> parent of 418abfb... add hash funtion and shrink entry size

        return 0;
    }
