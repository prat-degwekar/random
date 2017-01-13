#include <iostream>

using namespace std;

int gcd(int x , int y)
{
    if(x==0)return y;
    if(y==0)return x;
    if(x==y)
        return x;
    if(y>x)
        return gcd(y,x);
    return gcd((x%y) , y);
}

int gcd(int arr[] , int u , int l)
{
    if(u==l)
        return arr[l];

    return gcd(gcd( arr , u , (u+l)/2 + 1 ) , gcd( arr , (u+l)/2 , l));
}

int main()
{
    cout << "Hello world!" << endl;
    cout<<"enter \n1 . 2 numbers\n2 . array of numbers : ";
    int ch=0 , x=0 , y=0 , n=0 , k=0 , arr[25] = {0};
    cin>>ch;
    switch(ch)
    {
        case 1 : cout<<"enter 2 nums : ";
                 cin>>x>>y;
                 k = gcd(x,y);
                 cout<<"GCD = "<<k<<endl;
                 break;

        case 2 : cout<<"enter number of numbers : ";
                 cin>>n;
                 cout<<"enter numbers : ";
                 for(int i = 0 ; i<n ; i++)
                    cin>>arr[i];

                 k = gcd(arr , n-1 , 0);
                 cout<<"GCD = "<<k<<endl;
                 break;

        default : cout<<"invalid choice\n\n";
                  break;
    }
    return 0;
}
