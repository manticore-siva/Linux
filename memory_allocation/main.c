#include <stdio.h>
#include <stdlib.h>

int main(){

    char *ptr, i=10;

    ptr = (char *)malloc(1);

    *ptr = i;

    printf("%d\n",*ptr);

    int *p = (int *)10;


    printf("%d\n",*p);

    free(ptr);
}
