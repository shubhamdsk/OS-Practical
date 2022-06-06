#include <stdio.h>

void main()
{
    int pn = 0;                 //Processes Number
    int CPU = 0;            //CPU Current time
    int allTime = 0;        // Time neded to finish all processes
    printf("Enrer Processes Count: ");
    scanf("%d",&pn);
    int AT[pn];
    int ATt[pn];
    int NoP = pn;
    int PT[pn];             //Processes Time
    int PP[pn];             //Processes piriorty
    int waittingTime[pn];
    int turnaroundTime[pn];
    
    //Scanning Time and Piriorty
    for(int i=0 ;i<pn ;i++){
        printf("\nProcessing time for P%d: ",i+1);
        scanf("%d",&PT[i]);
        printf("Piriorty for P%d: ",i+1);
        scanf("%d",&PP[i]);
        printf("Arrival Time for P%d: ",i+1);
        scanf("%d",&AT[i]);
        ATt[i] = AT[i];
    }
    
    int LAT = 0;        //LastArrivalTime
    for(int i = 0; i < pn; i++)
        if(AT[i] > LAT)
            LAT = AT[i];
            
    int ATv = AT[0];    //Pointing to Arrival Time Value
    int ATi = 0;        //Pointing to Arrival Time indix
    int P1 = PP[0];     //Pointing to 1st piriorty Value
    int P2 = PP[0];     //Pointing to 2nd piriorty Value
   
    
    //findding the First Arrival Time and Highst piriorty Process
   
    while(NoP > 0 && CPU <= 1000){
        for(int i = 0; i < pn; i++){
            if(ATt[i] < ATv){
                ATi = i;
                ATv = ATt[i];
                P1 = PP[i];
                P2 = PP[i];
            }
            else if(ATt[i] == ATv || ATt[i] <= CPU){
                if(PP[i] != (pn+1))
                    P2 = PP[i];
                    if(P2 < P1){
                        ATi = i;
                        ATv = ATt[i];
                        P1 = PP[i];
                        P2 = PP[i];
                    }
            }
        }
        if(CPU < ATv){
            CPU = CPU+1;
            continue;
        }else{
            
           
            waittingTime[ATi] = CPU - ATt[ATi];
            CPU = CPU + PT[ATi];
            turnaroundTime[ATi] = CPU - ATt[ATi];
            ATt[ATi] = LAT +10;
            ATv = LAT +10;  //Pointing to Arrival Time Value
            ATi = 0;        //Pointing to Arrival Time indix
            PP[ATi] = pn + 1;
            P1 = PP[0];     //Pointing to 1st piriorty Value
            P2 = PP[0];     //Pointing to 2nd piriorty Value
            printf("Iam in");
            NoP = NoP - 1;
           
        }
            
    }
    
    printf("\nPN\tPT\tPP\tWT\tTT\n\n");
    for(int i = 0; i < pn; i++){
       printf("P%d\t%d\t%d\t%d\t%d\n",i+1,PT[i],PP[i],waittingTime[i],turnaroundTime[i]);
    }
   
    int AvgWT = 0;
    int AVGTaT = 0;
    for(int i = 0; i < pn; i++){
        AvgWT = waittingTime[i] + AvgWT;
        AVGTaT = turnaroundTime[i] + AVGTaT;
    }
   
   
   printf("Average Waiting Time = %d\n Average Turnaround Time = %d\n",AvgWT/pn,AVGTaT/pn);
}


