#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<process.h>
#include<io.h>

int main()
{
    pid_t child_pid;

    printf("The main program process id is %d\n", (int) getpid());

    child_pid = fork();
    
    if(child_pid != 0){
    	
       printf("This is parent process id is %d\n", (int) getpid()) ;
       printf("The child's process id is %d\n", (int) child_pid); 
    }
    
    else

    printf("This is the child process, with id is %d\n", (int) getpid());

    return 0;

}
// fork used for creating new process i.e. child process..
// it returns 2 values one to parent nd second to child class 

// used to execute file whose path is given :> execv
// used to execute file it takes path evnv :> execvp
