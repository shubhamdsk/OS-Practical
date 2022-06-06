/*
* fcfs.c
*/
    #include<stdio.h>
    #include<string.h>

    struct process
    {
    char pname[10];
    int AT,BT,ST,FT,TT,WT;
    }p[45];

    struct process t;
    int i,n,j,k,bt;
    char GC[50];

    void get_data()
    {
        printf("Enter number of processes : ");
        scanf("%d",&n);
        printf("Enter process details for %d processes : ",n);

        for(i=0;i<n;i++)
        {
            printf("\nEnter Process name,arival time,cpu burst time : ");
            scanf("%s%d%d",p[i].pname,&p[i].AT,&p[i].BT);
        }//for
    }//getdata

    void put_data()
    {
        printf("\nProcesses are as below");
        printf("\nProcess name\t arival time\t cpu burst time\tfinish time\tstart time");
        for(i=0;i<n;i++)
        {
            printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].FT,p[i].ST);
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
            p[i].WT=p[i].ST-p[i].AT;
            sumtt=sumtt+p[i].TT;
            sumwt=sumwt+p[i].WT;
        }//for
            printf("\n Process\tAT\tBT\tTT\tWT\tST\tFT\n");
            
            for(i=0;i<n;i++)
            {
                printf("\n%s\t\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].TT,p[i].WT,p[i].ST,
                p[i].FT);
            }//for

                printf("\n\nAverage turn around time=%0.2f/%d = %0.2f",sumtt,n, sumtt/n);
                printf("\n\nAverage wait time=%0.2f/%d = %0.2f\n",sumwt,n, sumwt/n);
    }//avgTTWT


    void fcfs()
    {
        char str[5];
        int time=0;
        strcat(GC,"0");
        for(i=0;i<n;i++)
        {
            strcat(GC,"|");
            if(p[i].AT>time) // GC = 0|CPUIDLE 2|J2 5|J1
            {
                strcat(GC,"CPUIDLE");
                time=p[i].AT;
                sprintf(str,"%d",time);
                strcat(GC,str);
                strcat(GC,"|"); 

            }//if

            p[i].ST=time; //time=0 2 5
            strcat(GC,p[i].pname);
            bt=p[i].BT;
            k=0;

            while(bt!=0)
            {
                strcat(GC," ");
                bt--;
                k++;
            }//while

            time=time+k;
            p[i].FT=time;
            sprintf(str,"%d",time);
            strcat(GC,str);
        }//for

            printf("\n\nGantt Chart\n");
            puts(GC);
            avgTTWT();
    }//fcfs

    int main()
    {
        get_data();
        put_data();
        arrivalsort();
        printf("\nProcesses after sorting on arrival time\n");
        put_data();
        fcfs();
    }//main
/*

Enter number of processes : 5
Enter process details for 5 processes : 
Enter Process name,arival time,cpu burst time : p1 0 10

Enter Process name,arival time,cpu burst time : p2 4 3  

Enter Process name,arival time,cpu burst time : p3 3 2  

Enter Process name,arival time,cpu burst time : p4 5 16

Enter Process name,arival time,cpu burst time : p5 2 8  

Processes are as below
Process name     arival time     cpu burst time finish time     start time
p1              0               10              0               0
p2              4               3               0               0
p3              3               2               0               0
p4              5               16              0               0
p5              2               8               0               0
Processes after sorting on arrival time

Processes are as below
Process name     arival time     cpu burst time finish time     start time
p1              0               10              0               0
p5              2               8               0               0
p3              3               2               0               0
p2              4               3               0               0
p4              5               16              0               0

Gantt Chart
0|p1          10|p5        18|p3  20|p2   23|p4                39

 Process        AT      BT      TT      WT      ST      FT

p1              0       10      10      0       0       10
p5              2       8       16      8       10      18
p3              3       2       17      15      18      20
p2              4       3       19      16      20      23
p4              5       16      34      18      23      39
Average turn around time=96.000000/5=19.200000
Average wait time=57.000000/5=11.400000
PS C:\Users\shubham Deshmukh\Desktop\College\Os> 
 */
