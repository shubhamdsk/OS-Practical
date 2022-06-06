#include<stdio.h>
int prs[20],frm[10]={0};
int m[50][50];
int tp,tf,totpf=0,currp=0,currf=0;
int i,j,pf,max,frmno,cnt;

	int chkpgfault()
	{
		for(i=0;i<tf;i++)
		{
			if(frm[i] == prs[currp])
			{
				break;
			}//if
		}//for

		if(i==tf)
		{
			return -1;
		}//if
		else
		{
			return i;
		}//else
	}//chkpgfault

	void displayFrame()
	{
		for(i=0;i<tf;i++)
		{
			m[currp][i] = frm[i];
		}//for
	}//displayFrame

	int nextFrame()
	{
		max = 0;
		frmno  = 0;
			for(i=0;i<tf;i++)
			{
				cnt = 0;
				for(j=currp+1;j<=tp;j++)
				{
					if(frm[i] == prs[j])
						break;
					else
						cnt++;
				}//jfor

				if(cnt>max)
				{
					max = cnt;
					frmno = i;
				}//if
			}//for
		return frmno;
	}//nextFrame

	void main()
	{
	printf("How many Page References String :");
	scanf("%d",&tp);

	printf("\nEnter Page References String :\n");
		for(i=0;i<tp;i++)
		{
			scanf("%d",&prs[i]);
		}//for
	printf("\nHow many Frames:\n");	
	scanf("%d",&tf);

	while(currp<tp)
	{
		pf = chkpgfault();
		if(pf== -1)
		{
			totpf++;
			currf = nextFrame();
			frm[currf] = prs[currp];
		}//if
		displayFrame();
		currp++;
	}//while

	printf("\n\tFrames\t\n");

	for(i=0;i<tf;i++)
		{
			for(j=0;j<tp;j++)
				{
					printf("%d ",m[j][i]);
				}//jfor
		printf("\n");
		}//ifor

	printf("\nTotal Page Fault:%d\n",totpf);	

	}//main
