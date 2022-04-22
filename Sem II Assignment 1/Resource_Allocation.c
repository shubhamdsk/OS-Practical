/*
* Resource Allocation
*
* Created on:
* Author: root
*/
#include<stdio.h>
int n,m,i,j,k,flag,safe;
int a[50][50],av[15],max[50][50],finish[10],need[50][50],req[10];
char s[50],str[5];
void get_data()
{
    printf("\nEnter number of processes : ");
    scanf("%d",&n);
    printf("\nEnter number of resources : ");
    scanf("%d",&m);
    printf("\n Enter allocation matrix : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }//for
    }//for
    printf("\n Enter MAX matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }//for
    }//for
    printf("\nEnter Available Array : ");
    for(i=0;i<m;i++)
         scanf("%d",&av[i]);
    for(i=0;i<n;i++)
         finish[i]=0;
}//get_data

void put_data()
{
    printf("\nAllocation matrix is.......\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
             printf("%d\t",a[i][j]);
        }//for
        printf("\n");
    }//for
    printf("\nMax matrix is.......\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
             printf("%d\t",max[i][j]);
        }//for
        printf("\n");
    }//for
    printf("\nAvailable Array is.....\n");
    for(i=0;i<m;i++)
        printf("%d\t",av[i]);
        printf("\nFinish Array\n");
    for(i=0;i<n;i++)
        printf("%d\t",finish[i]);
}

void calc_need()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-a[i][j];
        }
    }
    printf("\nNeed array is.....\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
             printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
}//calc_need

int check_need(int i)
{
    flag=0;
    for(j=0;j<m;j++)
    {
        if(need[i][j] > av[j])
        {
            flag=1;
            break;
        }//if
    }//for
    return flag;
}//check_need

void safe_state()
{
    for(i=0;i<n;i++)
        finish[i]=0;
        strcpy(s,"\0");
    for(i=0;i<n;i++)
    {
        if(check_need(i)==0)
        {
            for(k=0;k<m;k++)
            av[k]=av[k]+a[i][k];
            sprintf(str,"%d",i);
            strcat(s,"P");
            strcat(s,str);
            strcat(s," ");
            puts(s);
        }//if
        else
        finish[i]=1;
    }//for
}//safe_state

void res_req()
{
safe=0;
printf("Enter the process number\n");
scanf("%d",&i);
printf("Enter the request\n");
for(k=0;k<m;k++)
    scanf("%d",&req[k]);
    for(k=0;k<m;k++)
    {
        if(req[k] > need[i][k] || req[k] > av[k])
        {
            safe=1;
            break;
        }
    }

printf("\nEnter available array");
for(j=0;j<m;j++)
    scanf("%d",&av[j]);
if(safe==0)
    {
    printf("The request can be granted \n");
    for(k=0;k<m;k++)
    {
        av[k]=av[k]-req[k];
        a[i][k]=a[i][k]+req[k];
        need[i][k]=need[i][k]-req[k];
    }
    printf("\nNeed array is.....\n");
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
             printf("%d\t",need[i][j]);
            }
        printf("\n");
        }
    }//if
else
printf("\nThe request can not be granted");
}//res_req

void main()
{
int p,f;
f=0;
get_data();
put_data();
calc_need();
aaa: safe_state();
for(k=0;k<n;k++)
{
    if(finish[k]==1)
    {
        if(check_need(k)==0)
        {
            for(p=0;p<m;p++)
                av[p]=av[p]+a[k][p];
            sprintf(str,"%d",k);
            strcat(s,"P");
            strcat(s,str);
            strcat(s," ");
            finish[k]=0;
        }//if
        else
             f=1;
    }//if
}//for

if(f==0)
{
    printf("System is in safe state");
    printf("\nSafe sequence\n");
    puts(s);
}//if
else
    printf("System is not in safe state");
    res_req();
    put_data();
    if (safe==0)
    goto aaa;
}//main
/**************output***************
*
Enter number of processes : 5
Enter number of resources : 4
Enter allocation matrix :
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
Enter MAX matrix :
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
Enter Available Array : 1 5 2 0
Allocation matrix is.......
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
Max matrix is.......
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
Available Array is.....
1 5 2 0
Finish Array
0 0 0 0 0
Need array is.....
0 0 0 0
0 7 5 0
1 0 0 2
0 0 2 0
0 6 4 2
P0
P0 P2
P0 P2 P3
P0 P2 P3 P4
System is in safe state
Safe sequence
P0 P2 P3 P4 P1
Enter the process number
1
Enter the request
0 4 2 0
Enter available array1 5 2 0
The request can be granted
Need array is.....
0 0 0 0
0 3 3 0
1 0 0 2
0 0 2 0
0 6 4 2
Allocation matrix is.......
0 0 1 2
1 4 2 0
1 3 5 4
0 6 3 2
0 0 1 4
Max matrix is.......
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
Available Array is.....
1 1 0 0
Finish Array
0 0 0 0 0 P0
P0 P2
P0 P2 P3
P0 P2 P3 P4
System is in safe state
Safe sequence
P0 P2 P3 P4 P1
Enter the process number
*/