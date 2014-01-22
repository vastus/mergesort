#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

void
mergeSort(int *ary, int len)
{
    // Sorted when lt two items.
    if (len < 2) return;

    // Divide.
    int mid = len / 2;
    int *a = (int *) malloc(mid * sizeof(int));
    int *b = (int *) malloc((mid + (len % 2)) * sizeof(int));

    int i = 0, j = 0, k = 0;
    while (i < mid) a[i++] = ary[k++];
    while (j < (mid + (len % 2))) b[j++] = ary[k++];

    // Recur.
    mergeSort(a, mid);
    mergeSort(b, (mid + (len % 2)));

    // Conquer.
    merge(ary, len, a, mid, b, (mid + (len % 2)));

    // Free allocated memory.
    free(a);
    free(b);
}

void
merge(int *ary, int aryLen, int *a, int aLen, int *b, int bLen)
{
    int i = 0, j = 0, k = 0;
    while (i < aLen && j < bLen)
        ary[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];

    while (i < aLen) ary[k++] = a[i++];
    while (j < aLen) ary[k++] = b[j++];
}

