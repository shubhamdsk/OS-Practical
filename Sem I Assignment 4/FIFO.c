#include<stdio.h>
int prs[20],frm[10]={0};
int m[50][50];
int tp,tf,totpf=0,currp=0,currf=0;
int i,j,pf;

int chkpgfault()
{
    for(i=0;i<tf;i++){
        if(frm[i] == prs[currp])
        {
            break;
        }
    }
    if(i == tf)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

void displayFrame()
{
    for(i=0;i<tf;i++)
    {
        m[currp][i] = frm[i];
    }
    
}
void main()
{
    printf("How many Page References String : ");
    scanf("%d",&tp);

    printf("Enter Page References String :\n");
    for(i=0;i<tp;i++)
    {
        scanf("%d",&prs[i]);
    }

    printf("How many Frames : ");
    scanf("%d",&tf);

    while (currp<tp)
    {
        pf= chkpgfault();
        if (pf == -1)
        {
            totpf++;
            frm[currf] = prs[currp];
            currf++;

            if(currf == tf)
                currf = 0;
        }//if
        displayFrame();
        currp++;
    }//while

    printf("\n  Frames \n");
    for(i=0;i<tf;i++)
    {
        for(j=0;j<tp;j++)
            {
                printf("%d ",m[j][i]);
            }//jfor
            
            printf("\n");
    }//ifor

    printf("\nTotal Page Fault : %d",totpf);
}
