#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char argv[]){
    int pid = fork();
    if (pid == 0){ 
        set_ps_priority(10);
        exec("user/test_new_sched.c",0);
        
    }
    else{
        int n;
        wait(&n,0);
    }
    return 1;
}