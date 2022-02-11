#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXVALUE 1000

typedef struct entry
{
    void *key;
    void *value;
} entry;

typedef struct map
{
    entry **elem; // vectorul de elemente; este alocat si realocat dinamic
    int n_elem;   // numarul de elemente din vector
    int cap;      // capacitatea vectorului
} map;

int comp(const void *a, const void *b);
int compareEntry(const void *, const void *);
void printEntry(const entry *a);
void init(map *m, int cap);
void add(map *m, entry *e);
void print(map *m, void (*printEntry)(const entry *));
void sort(map *m, int (*fc)(const void *, const void *));
void del(map *m, void *k, int (*fc2)(const void *, const void *));
void *find(map *m, void *k, int (*fc)(const void *, const void *));