#include <stdio.h>

#include "lib/merge_sort.h"

void
printArr(int *, int);

int
main(int argc, char *argv[])
{
    int ary[] = {99, 54, -2, 77, 111};
    int len = sizeof(ary) / sizeof(ary[0]);

    printf("Merge sort:\n");
    printArr(ary, len);
    mergeSort(ary, len);
    printArr(ary, len);

    return 0;
}

void
printArr(int *ary, int len)
{
    printf("[");
    for (int i = 0; i < (len - 1); i++)
        printf("%d, ", ary[i]);
    printf("%d]\n", ary[(len -1)]);
}

