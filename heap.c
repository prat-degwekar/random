#include <stdio.h>
#include <stdlib.h>

void heapify(int *arr , int n , int i)
{
   int lar = i;
   int l = 2*i+1;
   int r = 2*i+2;

   if(l<n && arr[l] > arr[lar])
      lar = l;
   if(r<n && arr[r] > arr[lar])
      lar = r;
   if(lar!=i)
   {
      //swap
      int temp = arr[lar];
      arr[lar] = arr[i];
      arr[i] = temp;
      //swap
      heapify(arr , n , lar);
   }
}//heapify

void print(int *arr , int n)
{
   int i=0;
   printf("printit : ");
   for(i=0 ; i<n ; i++)
   {
      printf(" %d , " , arr[i]);
   }
   printf("\n\n");
}

void heapsort(int *arr , int n)
{
   int i=0;
   for(i = n/2-1 ; i>=0 ; i--)
   {
      heapify(arr , n , i);
   }

   for(i = n-1 ; i>=0 ; i--)
   {
      //swap i & 0
      int temp = arr[i];
      arr[i] = arr[0];
      arr[0] = temp;
      //swap done
      //n--;
      heapify(arr , i , 0);
   }

   printf("SORTED\n------\n");

   print(arr , n);
}

void main()
{
   int *arr = (int *)malloc(5*sizeof(int));
   int i = 0;
   int n=0;
   printf("enter no. of ints : ");
   scanf("%d" , &n);
   printf("enter %d integers : " , n);
   for(i=0 ; i<n ; i++)
      scanf("%d" , &arr[i]);

   print(arr , n);

   heapsort(arr,n);

}//main()
