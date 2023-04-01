//#include <stdio.h>
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char argv[]){
    printf("memsize test\n");
    printf("%d\n",memsize());
    int * allocate = (int*) malloc(20000);
    printf("%d\n",memsize());
    free(allocate);
    printf("%d\n",memsize());
    exit(0,0);
}