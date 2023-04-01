//#include <stdio.h>
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(int argc, char argv[]){
    printf("memsize test\n");
    int * allocate = (int*) malloc(20000);
    printf("%d\n",memsize());
    free(allocate);
    printf("%d\n",memsize());
    exit2(0,"hellooo");
}