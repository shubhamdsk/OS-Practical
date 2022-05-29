#include<stdio.h>
#include<math.h>

int main()
{
    int queue[100],i,n,seek=0,head,count=0;
    float avg;
    printf("Enter the number of Requests : \n");
    scanf("%d",&n);
    printf("Enter the Requests sequence : \n");
    for(i=0;i<n;i++)
     scanf("%d",&queue[i]);
    printf("Enter head head position : \n");
    scanf("%d",&head);
    
    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(queue[i]-head);     
           if(min>d)                 
           {                          
               min=d;                
               index=i;
           }
           
        }
        seek=seek+min;
        printf("\nDisk head moves from %d to %d with  seek %d",head,queue[index],min); 
        head=queue[index];
        queue[index]=1000;
        count++;
    }
    
    printf("\n\nTotal head movement is %d \n",seek);
    avg=seek/(float)n;
    printf("Average seek time is %0.2f\n",avg);
    return 0;
}
/*
o/p

Enter the number of Requests : 
5
Enter the Requests sequence : 
23 89 42 132 187
Enter head head position : 
100

Disk head moves from 100 to 89 with  seek 11
Disk head moves from 89 to 132 with  seek 43
Disk head moves from 132 to 187 with  seek 55
Disk head moves from 187 to 42 with  seek 145
Disk head moves from 42 to 23 with  seek 19

Total head movement is 273
Average seek time is 54.59
*/