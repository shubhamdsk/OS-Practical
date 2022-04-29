#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
typedef struct dir
{
 char fname[20];
 int start;
 struct dir *next;
}NODE;
NODE *head,*last,*temp,*prev,*dell,*tmp;
int n,bit[MAX],fb=0;

void init()
{
 int i;
 printf("Enter total no.of disk blocks:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
	bit[i]=rand()%2;
 }
}

void show_bitvector()
{
 int i;
 for(i=0;i<n;i++)
  printf("%d ",bit[i]);
 printf("\n");
}

void show_dir()
{
 NODE *temp;
 int i;
 printf("\n Directory "); 
 printf("\n File Name     Allocated Block Number "); 
 for(temp=head;temp!=NULL;temp=temp->next)
  {
  printf("\n   %s",temp->fname);  
  printf("           %d",temp->start);
  }
 

printf("\n\n Allocated Blocks :  "); 
for(temp=head;temp!=NULL;temp=temp->next)
  {
   printf("%d->",temp->start);
  }
 printf("NULL\n\n");
}

void create()
{
 NODE *p;
 char fname[20];
 int i,j,nob;
 int fb=0;
 printf("Enter file name:");
 scanf("%s",&fname);
 printf("Enter no.of blocks:");
 scanf("%d",&nob);
 for(i=0;i<n;i++)
 {
  if(bit[i]==0) 
    fb++; 
 }
if(nob>fb)
 {
  printf("Failed to create file %s\n",fname);
  return;
 }
 else
 {
    for(i=0;i<n;i++)  
	{
	if(bit[i]==0 && nob!=0) 
         {
		p = (NODE*)malloc(sizeof(NODE));   
		strcpy(p->fname,fname);                     
		nob--;                            
		bit[i]=1;                           
		p->start=i;                         
		p->next=NULL;                       
		if(head==NULL)
                   head=p;                        
		else
        	  last->next=p;
               last=p;
	}
       }
    printf("File %s created successully.\n",fname);
 } 
}
void delete()
{
   int i=0; 
   NODE *p,*q;
   char fname[20];
	
  temp=head;
  printf("Enter file to be deleted:");
  scanf("%s",fname);

  while(temp!=NULL)
    {
	p = q = head;
	while(p!=NULL)
	{
           if(strcmp(p->fname,fname)==0)
			break;
           q = p;
           p = p->next;
	}

	if(p==NULL)
	{
	   return;
	}


	if(p==head)
		head = head->next;
	else if(p==last)
	      {
		last=q;
		last->next=NULL;
	      }
	    else
             {
		q->next = p->next;
             }
        bit[p->start]=0;
	free(p);
   temp=temp->next;
  }

	printf("File %s deleted successfully.\n",fname);

}

  
int main()
{
 int ch;
 init();
 while(1)
 {
  printf("1.Show bit vector\n");
  printf("2.Create new file\n");
  printf("3.Show directory\n");
  printf("4.Delete file\n");
  printf("5.Exit\n");
  printf("Enter your choice (1-5):");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:show_bitvector(); break;
  case 2: create(); break;
  case 3:show_dir(); break;
  case 4: delete();break;
  case 5: exit(0);
  }
}
return 0;
}