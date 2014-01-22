#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

void
mergeSort(int *ary, int len)
{
    // Sorted when lt two items.
    if (len < 2) return;

    // Divide.
    int aLen = len / 2;
    int bLen = aLen + (len % 2);
    int *a = (int *) malloc(aLen * sizeof(int));
    int *b = (int *) malloc((aLen + (len % 2)) * sizeof(int));

    int i = 0, j = 0, k = 0;
    while (i < aLen) a[i++] = ary[k++];
    while (j < bLen) b[j++] = ary[k++];

    // Recur.
    mergeSort(a, aLen);
    mergeSort(b, bLen);

    // Conquer.
    merge(ary, len, a, aLen, b, bLen);

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

