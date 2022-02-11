#include "main.h"

int compareEntry(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a == *(int *)b)
        return 0;
    else
        return -1;
}

int compareKey(const void *a, const void *b)
{
    if (strcmp(((entry *)a)->key, ((entry *)b)->key) < 0)
        return 1;
    else if (strcmp(((entry *)a)->key, ((entry *)b)->key) == 0)
        return 0;
    else
        return -1;
}

void printEntry(const entry *a)
{
    printf("%s  %s\n", a->key, a->value);
}

void init(map *m, int cap)
{
    m->elem = malloc(cap * sizeof(entry *));
}

void add(map *m, entry *e)
{
    if (m->n_elem == m->cap - 1)
    {
        m->elem = realloc(m->elem, ++m->cap * sizeof(entry *));
    }
    m->elem[m->n_elem] = e;
}

void print(map *m, void (*printEntry)(const entry *))
{
    for (int i = 0; i < m->n_elem; i++)
    {
        printEntry(m->elem[i]);
    }
}

void sort(map *m, int (*fc)(const void *, const void *))
{
    qsort(m, m->n_elem, sizeof(entry *), fc);
}

void del(map *m, void *k, int (*fc2)(const void *, const void *))
{
    for (int i = 0; i < m->n_elem; i++)
    {
        if (fc2(m->elem[i], k) == 0)
        {
            for (int j = i; j < --m->n_elem; j++)
            {
                m->elem[j] = m->elem[j + 1];
            }
            m->elem = realloc(m->elem, --m->cap * sizeof(entry *));
        }
    }
}

void *find(map *m, void *k, int (*fc)(const void *, const void *))
{
    int *a;
    a = bsearch(k, m->elem, m->n_elem, sizeof(entry *), fc);
    return a - m->elem;
}

int main()
{
    
}