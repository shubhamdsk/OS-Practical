/*
Premptive SJF
*/

#include<stdio.h>
#include<string.h>
struct process
{
    char pname[10];
    int AT,BT,ST,FT,TT,WT,BT1;
}p[15];

    struct process t;
    int i,n,j,k,bt,tq;
    char GC[250];

        void get_data()
        {
            printf("Enter number of processes : ");
            scanf("%d",&n);

            printf("Enter process details for %d processes :",n);
            for(i=0;i<n;i++)
            {
                printf("\nEnter Process name,arival time,cpu burst time : ");
                scanf("%s %d %d",&p[i].pname,&p[i].AT,&p[i].BT);
                p[i].BT1=p[i].BT;
            }//for
        }//getdata

        void put_data()
        {
            printf("\n\nProcesses are as below:\n");
            printf("\n\nProcess name\t arival time\t cpu burst time");
            for(i=0;i<n;i++)
            {
                printf("\n%s\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT);
            }//for
        }//putdata

        void arrivalsort()
        {
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(p[i].AT > p[j].AT)
                    {
                        t=p[i];
                        p[i]=p[j];
                        p[j]=t;
                    }//if
                }//for
            }//for
        }//arrivalsort

    void burstsort()
    {
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(p[i].BT > p[j].BT)
                {
                    t=p[i];
                    p[i]=p[j];
                    p[j]=t;
                }//if
            }//for
        }//for
    }//burstsort

        void avgTTWT()
        {
            float sumtt=0,sumwt=0;
            for(i=0;i<n;i++)
            {
                p[i].TT=p[i].FT-p[i].AT;
                p[i].WT=p[i].TT-p[i].AT;
                sumtt=sumtt+p[i].TT;
                sumwt=sumwt+p[i].WT;
            }//for
                printf("\n Process\tAT\tBT\tTT\tWT\n");
                    for(i=0;i<n;i++)
                    {
                        printf("\n%s\t\t%d\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT1,p[i].TT,p[i].WT);
                    }//for
                    
                printf("\n\nAverage turn around time=%0.2f/%d = %0.2f",sumtt,n, sumtt/n);
                printf("\n\nAverage wait time=%0.2f/%d = %0.2f\n",sumwt,n, sumwt/n);

                
        }//avgTTWT

    void pre_sjf()
    {
        char str[5];
        i=0;
        int time = 0;
        tq = 1;
            strcpy(GC,"0|");
                 aaa:
                    if(p[i].BT!=0)
                    {
                        if(p[i].AT>time)
                        {
                            for(j=i+1;j<n;j++)
                            {
                                if (p[i].AT > p[j].AT && p[j].BT!= 0)
                                {
                                    time=p[j].AT;
                                    sprintf(str,"%d",time);
                                    strcat(GC,str);
                                    strcat(GC,"|");
                                    p[j].ST=time;

                                    strcat(GC,p[j].pname);
                                    p[j].BT=p[j].BT-bt;
                                    strcat(GC," ");

                                    time=time+tq;
                                        sprintf(str,"%d",time);
                                        strcat(GC,str);
                                        p[j].FT=time;
                                }//if
                            }//for
                        }//if
                        
                        p[i].ST=time;
                        strcat(GC,p[i].pname);
                        time=time+tq;
                        strcat(GC," ");

                        p[i].FT=time;
                        sprintf(str,"%d",time);
                        strcat(GC,str);
                        strcat(GC,"|");
                        p[i].BT=p[i].BT-tq;
                        burstsort();
                    }//if

                for(i=0;i<n;i++)
                    {
                        if(p[i].BT!=0)
                            goto aaa;
                    }//for

                    printf("\n\n\t\tGantt Chart\n\n");
                    puts(GC);
                    avgTTWT();
    }
            int main()
            {
                get_data();
                put_data();
                arrivalsort();
                put_data();
                pre_sjf();
            }//main

    /*
PS C:\Users\shubham Deshmukh\Desktop\College\Os\CPU Sheduling> gcc Pre_sjf.c
PS C:\Users\shubham Deshmukh\Desktop\College\Os\CPU Sheduling> ./a.exe      
Enter number of processes : 3
Enter process details for 3 processes :
Enter Process name,arival time,cpu burst time : p1 0 9

Enter Process name,arival time,cpu burst time : p2 1 5

Enter Process name,arival time,cpu burst time : p3 2 10


Processes are as below:


Process name     arival time     cpu burst time
p1              0               9
p2              1               5
p3              2               10

Processes are as below:


Process name     arival time     cpu burst time
p1              0               9
p2              1               5
p3              2               10

                Gantt Chart

0|p1 1|p2 2|p2 3|p2 4|p2 5|p2 6|p1 7|p1 8|p1 9|p1 10|p1 11|p1 12|p1 13|p1 14|p3 15|p3 16|p3 17|p3 18|p3 19|p3 20|p3 21|p3 22|p3 23|p3 24|

 Process        AT      BT      TT      WT

p2              1       5       5       4
p1              0       9       14      14
p3              2       10      22      20

Average turn around time=41.00/3 = 13.67

Average wait time=38.00/3 = 12.67
    */