#include <stdio.h>

extern sys_memsize;

void main(int argc, char *argv[]){
    int i=sys_memsize();
    print(i);
}