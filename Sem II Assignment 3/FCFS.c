// C program for FCFS disk scheduling 

#include<stdio.h>
#include<math.h>
int main()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff;
            float avg;
            printf("\nEnter the max range of disk : \n");
            scanf("%d",&max);
            printf("Enter the size of queue request : \n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read :\n");
            for(i=1;i<=n;i++)
            scanf("%d",&queue[i]);
            printf("Enter the initial head position : \n");
            scanf("%d",&head);
            queue[0]=head;
            for(j=0;j<=n-1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("\nDisk head moves from %d to %d with  seek %d",queue[j],queue[j+1],diff);
            }
            printf("\n\nTotal seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time is %0.2f\n",avg);
            return 0;
}

/*
o/p

Enter the max range of disk :
200
Enter the size of queue request : 
8
Enter the queue of disk positions to be read :
98 183 41 122 14 124 65 67
Enter the initial head position : 
53

Disk head moves from 53 to 98 with  seek 45
Disk head moves from 98 to 183 with  seek 85
Disk head moves from 183 to 41 with  seek 142
Disk head moves from 41 to 122 with  seek 81
Disk head moves from 122 to 14 with  seek 108
Disk head moves from 14 to 124 with  seek 110
Disk head moves from 124 to 65 with  seek 59
Disk head moves from 65 to 67 with  seek 2

Total seek time is 632
Average seek time is 79.00

*/
