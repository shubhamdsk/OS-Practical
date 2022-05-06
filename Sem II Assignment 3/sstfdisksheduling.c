
  // SSTF Disk Scheduling Algorithm
   
#include<stdio.h>
#include<math.h>

int main()
{
    int queue[100],i,n,seek=0,head,count=0;
    float avg;
    printf("\n Enter the number of Requests : ");
    scanf("%d",&n);
    printf("\n Enter the Requests sequence : ");
    for(i=0;i<n;i++)
     scanf("%d",&queue[i]);
    printf("Enter head head position\n");
    scanf("%d",&head);
    
        
        /* loop will execute until all process is completed*/
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
        queue[index]=1000;       // 1000 is for max
        count++;
    }
    
    printf("\n Total head movement is %d \n",seek);
    avg=seek/(float)n;
    printf("\n Average seek time is %f\n",avg);
    return 0;
}
