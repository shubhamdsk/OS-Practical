#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bv[50],i,st,j,len,c,k;
char name[10][30];
int start[10],length[10],num=0;

void dislayBitVector()
{
  printf("\n Bit Vector contents \n");
  for(i=0;i<50;i++)
     printf(" %d ",bv[i]);
}//dislayBitVector

void createFile()
{
    char temp[30];
    printf("Enter the name of the file :");
    scanf("%s",&temp);
    for(int i=0;i<num;i++)
            if(strcmp(name[i],temp)==0) 
            {
            printf("\n Filename already exists");
            return;
            }//if
    strcpy(name[num],temp);
    printf("Enter the start block of the file : ");
    scanf("%d",&start[num]);
    printf("Enter the length of the file : ");
    scanf("%d",&length[num]);
    
    for(j=start[num];j<(start[num]+length[num]);j++)
      if(bv[j]==1)
        {  
                printf("File can not be allocated...Block already allocated");
                strcpy(name[j],"-");   
                start[j]=0;
                length[j]=0; 
                return;
        }//if
    
     for(j=start[num];j<(start[num]+length[num]);j++)
       { 
        bv[j]=1;
        printf("\n%d->%d",j,bv[j]);
        }//for
    num++;
}//creteFile

void showDirectory()
{
  printf("Directory contents\n");
    printf("%s%40s%40s\n","File Name","Start Block","Length");
   
    for(int i=0;i<num;i++)
    {
        if(strcmp(name[i],"-")!=0)
            {
                printf("%s%40d%40d\n",name[i],start[i],length[i]);
            }//if
    }//for
}//showDirectory

void deleteFile()
{  
    char temp[10];
   
    printf("\nEnter the name of the file to delete  :");
    scanf("%s",&temp);
    for(int i=0;i<num;i++)
    {
     if(strcmp(name[i],temp)==0)
       {  
          for(j=start[i];j<(start[i]+length[i]);j++)
            {
            bv[j]=0;
            printf("\n%d->%d",j,bv[j]);
            }//for
          printf("\n File successfully deleted..");
          strcpy(name[i],"-");   
          start[i]=0;
          length[i]=0; 
          return;
       }//if  
    }//for
       printf("\n File not found..");
}//deleteFile

int main()
{
  int ch=0;
  for(i=0;i<50;i++)
     bv[i]=0;
   do
   {
        printf("\n *** Menu ****");
        printf("\n 1. Show Bit Vector");
        printf("\n 2. Create New File");
        printf("\n 3. Show Directory");
        printf("\n 4. Delete File");
        printf("\n 5. Exit");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: dislayBitVector();
                break;
        case 2: createFile();
                break;
        case 3: showDirectory();
                break;
        case 4: deleteFile();
                break;
        } //switch      
   }while(ch!=5);
      
}//main