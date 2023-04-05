#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int pid = fork();
    if (pid == 0){ 
        int cpid = fork();
        if (cpid==0) {
            set_ps_priority(1);
            char *args[]={"task5_loop","##\n",0};
            exec("task5_loop",args);
        }
        else{
            set_ps_priority(10);
            char *args[]={"task5_loop","@@\n",0};
            exec("task5_loop",args);
        }     
    }
    else{
        int n;
        wait(&n,0);
    }

    return 1;
}