#include <stdio.h>
#include <stdlib.h>

void printit(int **arr , int n)
{
   printf("\n\nmatrix\n\n");
   int i=0,j=0;
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
	 printf(" %d ",arr[i][j]);
      printf("\n");
   }
   printf("\n\n\n");
}

void printvis(int *vis , int n)
{
   int i=0;
   printf("\n\nvisited array : ");
   for(i=0;i<n;i++)
   {
      printf(" %d ",vis[i]);
   }
   printf("\n\n");
}//print visited

int dfs(int n , int **arr , int f , int t , int *vis)
{
   if(arr[f][t] == 1)
   {
      printf(" PATH COMPLETE <=== %d  ",t);
      return 1;
   }

   int i=0;
   for(i=0;i<n;i++)
   {
      if(i==f)
	 continue;
      if(arr[f][i] == 1 && vis[i]==0)
      {
	 vis[i]=1;
	 int k = dfs(n,arr,i,t,vis);
	 //printvis(vis,n);
	 //printf("for f = %d & t = %d , k = %d\n",i,t,k);
	 if(k==1)
	 {
	    printf(" <-- %d ",i);
	    return 1;
	 }
      }//if(k)

   }//for(i)

   return 0;

}//dfs(n,arr,f,t)

void main()
{
   int n=0;
   printf("enter the no. of nodes : ");
   scanf("%d",&n);
   int **arr = (int **)malloc(n*sizeof(int *));
   int i=0;
   for(i = 0 ; i<n; i++)
   {
      arr[i] = (int *)malloc(n*sizeof(int));
   }
   int j=0 , k=0 , g=0;
   
   int *vis = (int *)malloc(n*sizeof(int));

   for(j=0;j<n;j++)
      for(k=0;k<n;k++)
	 arr[j][k] = 0;

   j=0;
   k=0;
   i=0;
   while(i!=3)
   {
      printf("ENTER\n1 . ADD EDGE\n2 . DFS\n3 . EXIT : ");
      scanf("%d" , &i);
      switch(i)
      {
	 case 1 : printf("enter the two nodes : ");
		  scanf("%d %d",&j,&k);
		  arr[j][k] = 1;
		  arr[k][j] = 1;
		  printf("added\n\n");
		  break;

	 case 2 : printit(arr,n);
		  
		  printf("enter nodes to find path between : ");
		  scanf("%d %d",&j,&k);
		  for(g=0;g<n;g++)
		     vis[g]=0;
		  vis[j] = 1;
		  printf("\nhere safely\n\n");
		  k = dfs(n,arr,j,k,vis);
		  if(k==1) printf(" <-- %d\n",j);
		  printf("\n\nk = %d\n\n",k);
		  break;

	 case 3 : printf("you chose to quit.\n\n");
		  break;

	 default : printf("invalid choice\n\n");
		   break;

      }//switch(i)

   }//while(i)

   printf("GGWP\n\n");

}//main()

