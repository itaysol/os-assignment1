#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"






void
cfscheduler(void)
{
  struct proc *p;
  struct cpu *c = mycpu();
  c->proc = 0;
  for(;;){
    // Avoid deadlock by ensuring that devices can interrupt.
    intr_on();

    int vruntime = 0;
    struct proc *min_proc = 0;
    int foundOne = 0;

    for(p = proc; p < &proc[NPROC]; p++) {

      acquire(&p->lock);
      if(p->state == RUNNABLE) {
        if(!foundOne){
          min_accumulator = p->accumulator;
          min_proc = p;
          foundOne = 1;
        }
        else{
          if(p->accumulator < min_accumulator){
            min_accumulator = p->accumulator;
            release(&min_proc->lock);
            min_proc = p;
          }
          else{
             release(&p->lock);
          }
        }
      }
      else{
        release(&p->lock);
      }
     
    }
        // Switch to chosen process.  It is the process's job
        // to release its lock and then reacquire it
      // before jumping back to us.
      if(min_proc!=0){  
        min_proc->state = RUNNING;
        c->proc = min_proc;
        swtch(&c->context, &min_proc->context);
          // Process is done running for now.
          // It should have changed its p->state before coming back.
        c->proc = 0;
        release(&min_proc->lock);
      }
  }
}