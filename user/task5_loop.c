#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    for(int i =1;i<100;i++){
        write(1, argv[1], strlen(argv[1]));
        //printf("%s",argv[1]);
    }
    return 1;
}