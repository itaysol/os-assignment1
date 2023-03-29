//#include <stdio.h>
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(int argc, char argv[]){
    printf("memsize test\n");
    printf("%d\n",memsize());
    int * allocate = (int*) malloc(20>>10);
    printf("%d\n",memsize());
    free(allocate);
    printf("%d\n",memsize());
}