#include<stdio.h>
int main()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],
                        temp1=0,temp2=0;
            float avg;
            printf("Enter the max range of disk : \n");
            scanf("%d",&max);
            printf("Enter the initial head position : \n");
            scanf("%d",&head);
            printf("Enter the size of queue request : \n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read : \n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        if(temp>=head)
                        {
                                    queue1[temp1]=temp;
                                    temp1++;
                        }
                        else
                        {
                                    queue2[temp2]=temp;
                                    temp2++;
                        }
            }
            for(i=0;i<temp1-1;i++)
            {
                        for(j=i+1;j<temp1;j++)
                        {
                                    if(queue1[i]>queue1[j])
                                    {
                                                temp=queue1[i];
                                                queue1[i]=queue1[j];
                                                queue1[j]=temp;
                                    }
                        }
            }
            for(i=0;i<temp2-1;i++)
            {
                        for(j=i+1;j<temp2;j++)
                        {
                                    if(queue2[i]<queue2[j])
                                    {
                                                temp=queue2[i];
                                                queue2[i]=queue2[j];
                                                queue2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<temp1;i++,j++)
            queue[i]=queue1[j];
            queue[i]=max;
            for(i=temp1+2,j=0;j<temp2;i++,j++)
            queue[i]=queue2[j]; 
            queue[i]=0;
            queue[0]=head;  
            printf("\n queue[] :");
            for(j=0;j<=n+1;j++)
               printf(" %d ",queue[j]);
            for(j=0;j<=n+1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
             printf("\nDisk head moves from %d to %d with %d",queue[j],queue[j+1],diff);
            }
            printf("\n\nTotal seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time is %0.2f\n",avg);
            return 0;
            
}
/*
O/p

Enter the max range of disk : 
200
Enter the initial head position : 
100
Enter the size of queue request : 
5
Enter the queue of disk positions to be read : 
23 89 132 42 187

 queue[] : 100  132  187  200  89  42  23
Disk head moves from 100 to 132 with 32
Disk head moves from 132 to 187 with 55
Disk head moves from 187 to 200 with 13
Disk head moves from 200 to 89 with 111
Disk head moves from 89 to 42 with 47
Disk head moves from 42 to 23 with 19
Disk head moves from 23 to 0 with 23

Total seek time is 300
Average seek time is 60.00
*/