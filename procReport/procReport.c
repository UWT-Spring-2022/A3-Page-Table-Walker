#include<linux/module.h>
#include<linux/sched/signal.h>
#include<linux/pid_namespace.h>
#include<asm/io.h>


int proc_count(void) {
  int i=0;
  struct task_struct *thechild;
  for_each_process(thechild)
    i++;
  
  return i;
}


void proc_print(void) {
    struct task_struct *thechild;

    printk("PROCESS REPORT:");
    // printk("ONLY COUNTING THREADS WITH PID > 650");
    printk("proc_id, proc_name, contig_pages, noncontig_pages, total_pages");
    
    for_each_process(thechild) {
      if (thechild->pid > 650) {
          // printk("%d, %s, %ld, %ld, %ld", thechild->pid, thechild->comm, (thechild->mm)->contig_pages, (thechild->mm)->noncontig_pages,(thechild->mm)->total_pages);
          printk("%d, %s", thechild->pid, thechild->comm);
      }
    }
}



int proc_init (void) {
  printk(KERN_INFO "procReport: kernel module initialized\n");
  printk(KERN_INFO "There are %d running processes .\n", proc_count());
  proc_print();
  return 0;
}

void proc_cleanup(void) {
  printk(KERN_INFO "procReport: performing cleanup of module\n");
}



MODULE_LICENSE("GPL");
module_init(proc_init);
module_exit(proc_cleanup);

