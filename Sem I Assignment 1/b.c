#include<unistd.h>
#include<stdio.h>
#include<Sys/type.h>

int main(void)
{
    char *binaryPath ="C:\\Users\\shubham Deshmukh\\Desktop\\College\\Os\\hello";
    char *args[] = {binaryPath,NULL};
    printf("Not Working......");

    execv(binaryPath,args);
    
    return 0;
}
