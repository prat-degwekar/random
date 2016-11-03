#include <stdio.h>
#include <stdlib.h>

int f=-1,r=-1;
int q_n=0;

void bfs(int **arr , int *vis , int *q)
{
   int fr=0,t=0 , g=0;
   printf("enter nodes to find path : ");
   scanf("%d %d",&fr , &t);
   int i=0,j=0;
   for(i=0;i<q_n;i++)
      vis[i]=0;
    
   q[0] = fr;
   f=0;
   r=0;
   if(arr[f][t]==1)
   {
      printf("path : %d --> %d\n\n",f,t);
      return;
   }

   while(f<=r)
   {
      int k = q[f++];
      for(i=0;i<q_n;i++)
      {
	 if(i==k)
	    continue;
	 if(arr[k][t]==1)
	 {
	    printf(" PATH FOUND THROUGH %d\n\n",k);
	    return;
	 }
	 if(arr[k][i]==1 && vis[i]==0)
	 {
	    vis[i]=1;
	    q[r++]=i;
	    /*if(f==-1)
	       f=0;*/
	 }//if
      }
      //printf("node is %d\n",k);
      //printf("queue is : ");
      /*for(g=0;g<r ; g++)
	 printf(" %d ",q[g]);
      printf("\nfr = %d\n\n",f);*/
   }//while

   printf("peace\n\n");
}//bfs


void main()
{
   int i=0,j=0,k=0;
   printf("enter no. of nodes : ");
   scanf("%d",&q_n);
   int *q = (int *)malloc(q_n*sizeof(int *));
   int **arr = (int **)malloc(q_n*sizeof(int *));
   for(i=0;i<q_n;i++)
   {
      arr[i] = (int *)malloc(q_n*sizeof(int));
   }
   for(i=0;i<q_n;i++)
      for(j=0;j<q_n;j++)
	 arr[i][j]=0;

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

	 case 2 : bfs(arr,vis,q);
		  break;

	 case 3 : printf("you chose to exit!\n\n");
		  break;

	 default : printf("invalid choice\n\n");
		   break;
      }//switch(i)

   }//while(i)

   printf("GGWP\n\n");
}//main()
