#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char argv[]){
    for(;;){
        sleep(10);
        printf("hey");
    }
}