// C program for FCFS disk scheduling 

#include<stdio.h>
#include<math.h>
int main()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff;
            float avg;
            printf("\nEnter the max range of disk : ");
            scanf("%d",&max);
            printf("\nEnter the size of queue request : ");
            scanf("%d",&n);
            printf("\nEnter the queue of disk positions to be read : ");
            for(i=1;i<=n;i++)
            scanf("%d",&queue[i]);
            printf("\nEnter the initial head position :");
            scanf("%d",&head);
            queue[0]=head;
            for(j=0;j<=n-1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("\nDisk head moves from %d to %d with  seek %d",queue[j],queue[j+1],diff);
            }
            printf("\n Total seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("\n Average seek time is %f\n",avg);
            return 0;
}

