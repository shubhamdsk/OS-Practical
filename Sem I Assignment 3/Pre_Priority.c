#include<stdio.h>
#include<string.h>

struct process
{
    char pname[10];
    int AT,BT,ST,FT,TT,WT,BT1,PR;
}p[15];

struct process t;
    struct process t;
    int i,n,j,k,bt,tq,time;
    char GC[150];

        void get_data()
        {
            printf("Enter number of processes : ");
            scanf("%d",&n);

            printf("Enter process details for %d processes :",n);
            for(i=0;i<n;i++)
            {
                printf("\nEnter Process name,arival time,cpu burst time,priority: ");
                scanf("%s %d %d %d",&p[i].pname,&p[i].AT,&p[i].BT,&p[i].PR);
                p[i].BT1=p[i].BT;
            }//for
        }//getdata

        void put_data()
        {
            printf("\n\nProcesses are as below:\n");
            printf("\n\nProcess Name\t Arival Time\t CPU Burst Time\tPriority");
            for(i=0;i<n;i++)
            {
                printf("\n\t%s\t\t%d\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].PR);
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

        void avgTTWT()
        {
            float sumtt=0,sumwt=0;
            for(i=0;i<n;i++)
            {
                p[i].TT=p[i].FT-p[i].AT;
                p[i].WT=p[i].ST-p[i].BT1;
                sumtt=sumtt+p[i].TT;
                sumwt=sumwt+p[i].WT;
            }//for
                printf("\n Process\tAT\tBT\tTT\tWT\tST\tFT\n");
                    for(i=0;i<n;i++)
                    {
                        printf("\n%s\t\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT1,p[i].TT,p[i].WT,p[i].ST,p[i].FT);
                    }//for
                printf("\n\nAverage turn around time=%0.2f/%d = %0.2f",sumtt,n, sumtt/n);
                printf("\n\nAverage wait time=%0.2f/%d = %0.2f\n",sumwt,n, sumwt/n);
        }//avgTTWT

        void priority_sort()
        {
            for(i=0;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(p[i].PR > p[j].PR)
                        {
                            t=p[i];
                            p[i]=p[j];
                            p[j]=t;
                        }//if
                    }//for
                }//for
        }//prioritysort

        void pr()
        {
            char str[5];
            i=0;
            int time = 0;
            tq = 1;
            strcpy(GC,"0|");
            aaa:
                if(p[i].BT != 0)
                {
                    if(p[i].AT > time)
                    {
                        for(j=i+1; j<n;j++)
                        {
                            if(p[i].AT > p[j].AT && p[j].BT !=0)
                            {
                                time = p[i].AT;
                                sprintf(str,"%d",time);
                                strcat(GC,str);
                                strcat(GC,"|");
                                p[j].ST = time;
                                strcat(GC,p[j].pname);
                                p[j].BT = p[j].BT-tq;
                                strcat(GC," ");
                                time = time + tq;
                                sprintf(str,"%d",time);
                                strcat(GC,str);
                                p[j].FT = time;
                            }//if
                        }//for
                    }//if

                    p[i].ST = time;
                    strcat(GC,p[i].pname);
                    time = time + tq;
                    strcat(GC," ");
                    p[i].FT = time;
                    sprintf(str,"%d",time);
                    strcat(GC,str);
                    strcat(GC,"|");
                    p[i].BT = p[i].BT - tq;
                    priority_sort();

                }//if
                for(i=0;i<n;i++)
                {
                    if(p[i].BT != 0)
                        goto aaa;
                }//for

                printf("\n\n\t\tGantt Chart\n\n");
                puts(GC);
                avgTTWT();               
        }//pr

        int main()
        {
            get_data();
            put_data();
            arrivalsort();
            put_data();
            pr();
        }//main
