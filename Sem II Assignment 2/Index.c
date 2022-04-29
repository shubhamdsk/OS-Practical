#include<stdio.h>
#include<stdlib.h>
int f[50],index1[50],i, n, st, len, j, c, k, ind,count=0,cnt=0,key[50],blocks[50];

void show_bitvector()
{
printf("\n vector contents....\n");
for(i=0;i<50;i++)
    printf(" %d ",f[i]);
}

void show_dir()
{
 printf("\nIndex Block Number\n");
 for(k=0;k<cnt;k++)
       printf("%d-------->%d\n",key[k],blocks[k]);
}

void create()
{
   x:printf("\nEnter the index block: ");
   scanf("%d",&ind);
   if(f[ind]!=1)
     {
       printf("\nEnter number of blocks needed for the index %d on the disk : \n", ind);
       scanf("%d",&n);
      }
    else
      {
        printf("%d index is already allocated \n",ind);
        goto x;
      } 
   y: count=0;
      printf("\n Enter block numbers for the index %d on the disk : \n", ind);
      for(i=0;i<n;i++)
        {
        scanf("%d",&index1[i]);
        if(f[index1[i]]==0)
            count++;
        }                 
    if(count==n)            
       {                     
       key[cnt]=ind;         
       f[ind]=1;           
       for(j=0;j<n;j++)
        {
         f[index1[j]]=1;
         blocks[cnt]=index1[j];
         key[cnt]=ind; 
         cnt++;
        }
      printf("Allocated\n");
      printf("File Indexed\n");
      for(k=0;k<n;k++)
       printf("%d-------->%d : %d\n",ind,index1[k],f[index1[k]]); 
   }                                                              
  
else
   {
    printf("File in the index1 is already allocated \n");
    printf("Enter another file indexed");
    goto y;
   }
}
void deleteindex()
{ 
  int flag=0;
  printf("\nEnter the index block to delete: ");
  scanf("%d",&ind);
  for(i=0;i<cnt;i++)
     {
       if(key[i]==ind)
       {
         flag=1;
         f[ind]=0;
         printf("\n blocks = %d",blocks[i]);
         f[blocks[i]]=0;
         blocks[i]=0;
         key[i]=0;
        }
    }

  if(flag==1)
    printf("\n File deleted...\n\n");
  else
    printf("\n File not found.. \n\n");
}

int main()
{
 int ch;
 for(i=0;i<50;i++)
    f[i]=0;
 while(1)
 {
  printf("\n1.Show bit vector\n");
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
  case 4: deleteindex(); break;
  case 5: exit(0);
  }
}
return 0;
}