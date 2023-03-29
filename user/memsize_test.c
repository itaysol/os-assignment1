<<<<<<< HEAD
#include <stdio.h>

extern sys_memsize;

void main(int argc, char *argv[]){
    int i=sys_memsize();
    print(i);
=======
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
>>>>>>> f925b42a776b60fae32a2638ef24ea8659b22f3c
}