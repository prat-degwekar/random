#include <stdio.h>
#include <stdlib.h>

int f=-1,r=-1;
int q_n=0;

void printit(int **fin , int n)
{
   int i=0 , j=0;
   printf("final : \n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
	 printf("%d ",fin[i][j]);
      }
      printf("\n");
   }
   printf("\n\n\n");
}

void bfs(int **arr , int *vis , int *q , int **fin)
{
   int fr=0 , t=0 , g=0;
   int i=0,j=0;
   for(i=0;i<q_n;i++)
      vis[i]=0;
    
   q[0] = fr;
   f=0;
   r=0;

   while(f<=r)
   {
      int k = q[f++];
      for(i=0;i<q_n;i++)
      {
	 if(i==k)
	    continue;
	 if(arr[k][i]==1 && vis[i]==0)
	 {
	    printf("visiting %d\n\n",i);
	    fin[k][i] = 1;
	    fin[i][k] = 1;
	    vis[i]=1;
	    q[r++]=i;
	    
	 }//if
      }

void main()
{
   int i=0,j=0,k=0;
   printf("enter no. of nodes : ");
   scanf("%d",&q_n);
   int *q = (int *)malloc(q_n*sizeof(int *));
   int **arr = (int **)malloc(q_n*sizeof(int *));
   int **fin = (int **)malloc(q_n*sizeof(int *));
   for(i=0;i<q_n;i++)
   {
      arr[i] = (int *)malloc(q_n*sizeof(int));
      fin[i] = (int *)malloc(q_n*sizeof(int));
   }
   for(i=0;i<q_n;i++)
   {
      for(j=0;j<q_n;j++)
      {
	 arr[i][j]=0;
	 fin[i][j]=0;
      }
   }

   int *vis = (int *)malloc(q_n*sizeof(int));

   i=0;
   while(i!=3)
   {
      printf("CHOOSE\n1 . ADD EDGE\n2 . BFS\n3 . EXIT : ");
      scanf("%d",&i);
      switch(i)
      {
	 case 1 : printf("enter nodes : ");
		  scanf("%d %d",&j,&k);
		  arr[j][k] = 1;
		  arr[k][j] = 1;
		  printf("added\n");
		  break;

	 case 2 : bfs(arr,vis,q,fin);
		  printit(fin,q_n);
		  break;

	 case 3 : printf("you chose to exit!\n\n");
		  break;

	 default : printf("invalid choice\n\n");
		   break;
      }//switch(i)

   }//while(i)

   printf("GGWP\n\n");
}//main()
