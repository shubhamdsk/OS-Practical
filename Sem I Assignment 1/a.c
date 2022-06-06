#include<unistd.h>
int main(void)
{
    char *programName = "ls";
    char *args[] = {programName, "-lh", "/home", NULL};

    execvp(programName,args);
    return 0;
}