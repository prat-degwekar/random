#include <iostream>
#include <algorithm>

using namespace std;

int max1(int a[] , int n)
{
    int m=a[0];
    for(int i=1 ; i<n ; i++)
        if(a[i]>m)
            m = a[i];

    return m;
}

int max2(int a[] , int u , int l)
{
    if(u==(l+1) || u==l)
        return max(a[u] , a[l]);

    return max(max2(a , (u+l)/2 , l) , max2(a , u , (u+l)/2 + 1));
}

int max2(int a[],int n)
{
    return max2(a,n-1,0);
}

int max3(int a[] , int n)    //reductionist approach
{
    int chk=0;
    int dupe[n];

    for(int i=0 ; i<n ; i++)
        dupe[i] = a[i];

    for(int i=0;i<n;i++)
    {
        if(dupe[i]>0)
        {
            for(int j = 0 ; j<n ; j++)
                {
                    if(i==j)continue;
                    dupe[j]-=dupe[i];
                }

            dupe[i]=0;
            chk=1;
        }
    }

    if(chk==1 || true) //reduction occured and max got
    {
        for(int i=0 ; i<n ; i++)
        {
            if(dupe[i]==0)
            {
                return a[i];
            }
        }
    }

    //if all negatives
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
            dupe[j]-=dupe[i];
    }

    for(int i=0;i<n;i++)
    {
        if(dupe[i]>0)
        {
            for(int j = 0 ; j<n ; j++)
                {
                    if(i==j)
                        continue;

                    dupe[j]-=dupe[i];
                }

            dupe[i] = 0;

            chk=1;
        }
    }

    if(chk==1 || true) //reduction occured and max got
    {
        for(int i=0 ; i<n ; i++)
        {
            if(dupe[i]==0)
            {
                return a[i];
            }
        }
    }

}

int max4(int a[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(a[i]<a[j])
            {
                break;
            }
            if(j==(n-1))
            {
                if(a[i]>=a[j])
                {
                    return a[i];
                }
            }
        }
    }
}

int max5(int a[] , int n)
{
    int dupe[n];
    for(int i=0 ; i<n ; i++)
        dupe[i] = a[i];

    for(int i=0 ; i<n-1 ; i++)
    {
        if(dupe[i]>dupe[i+1])
        {
            int t = dupe[i];
            dupe[i] = dupe[i+1];
            dupe[i+1] = t;
        }
    }

    return dupe[n-1];
}

int max6(int a[] , int n)
{
    int dupe[n];
    for(int i=0 ; i<n ; i++)
        dupe[i] = a[i];

    sort(dupe , dupe+n);

    return dupe[n-1];
}

int heapush(int a[],int n) //NOTE - Array is taken as A[1:n];
{
    int i,j,e;
    j = n;
    i = n/2;
    e = a[n];

    while(i>0 && e>a[i])
    {
        a[j] = a[i];
        j = i;
        i = i/2;
    }

    a[j] = e;
}

int heapmaker(int a[],int n) //NOTE - Array is taken as A[1:n];
{
    for(int i = 2; i<=n ; i++)
        heapush(a,i);
}

int max7(int a[],int n) //NOTE - Array is taken as A[1:n];
{
    heapmaker(a,n);
    return a[1];
}

int max_avg(int a[], int n)
{
    if(n==1)
        return(a[0]);
    int avg, i, sum = 0;
    for(i = 0; i<n ; i++)
    {
        sum+=a[i];
    }
    avg = (float)sum/n;

    int j = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i]>=avg)
        {
            a[j++] = a[i];
        }
        if(j==n-1)
            return a[0];
    }

    return max_avg(a,j);
}

int getmax(int a[], int n, int c = 1)
{
    switch(c)
    {
        case 1: max1(a,n);break; //Classic
        case 2: max2(a,n);break; //Binary_Split
        case 3: max3(a,n);break; //Leveller
        case 4: max4(a,n);break; //Compare_All
        case 5: max5(a,n);break; //Bubbler
        case 6: max6(a,n);break; //Sorter
        case 7: max7(a,n);break; //Heapmaker (Takes array as A[1:n]
        case 8: max_avg(a,n);break; //Tail-Cutter
    }
}
int main()
{
    int a[] = {34,34,34,34,34};
    for(int i=1;i<=8;i++)
        cout<<getmax(a,5,i)<<" ";
}
