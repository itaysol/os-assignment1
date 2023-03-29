//#include <stdio.h>
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(int argc, char argv[]){
    printf("memsize test\n");
    int i = memsize();
    printf("%d\n",i);
}