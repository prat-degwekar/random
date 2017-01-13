#include<iostream>
#include<math.h>
using namespace std;

int swapper(int &x, int &y) //Bitwise XOR Swapper *Currently unoptimized*
{
    int f1,f2;
    f1 = f2 = 0;
    if(x<0)
    {
        x*=-1;
        f1 = 1;
    }
    if(y<0)
    {
        y*=-1;
        f2 = 1;
    }
    int i = 0; //Current digit marker (Iterator)
    int d = ceil(log2f(max(x,y))); //Reqd. digits for binary eqvt.;
    int bx[d],by[d]; //Binary eqvt. - Can be bool, taken int for convenience
    while(x>0 || y>0)
    {   //Start XOR Construct
        if(x%2==y%2) //Extract binary digit
            bx[i] = by[i] = x%2; //Retain bool binary digit on match
        else
        {
            bx[i] = 1-(x%2); //Invert bool binary digit on mismatch
            by[i] = 1-(y%2); //Can use NOT(!) on bool-type as well
        }
        //End XOR Construct
        x/=2; //Reduce number for further
        y/=2; //   digit extraction.
        i++;
    }

    for(i=0; i<d; i++) //Humanizing the scary-looking numbers
    {
        x+=(bx[i]*pow(2,i));
        y+=(by[i]*pow(2,i));
    }

    if(f1 == 1)
        y*=-1;
    if(f2 == 1)
        x*=-1;

}

int swap_classic(int &x , int &y) //Using aux. variable
{
    int t=0;
    t=x;
    x=y;
    y=t;
}

int swap_noAux(int &x , int &y) //Arithmetic Manipulation
{
    if((x>0 && y<0) || (x<0 && y>0))
    {
        x = x+y;
        y = x-y;
        x = x-y;
    }
    else
    {
        x = x-y;
        y = x+y;
        x = y-x;
    }

}

int main() //Drier
{
    int x = 1024;
    int y = 9878;
    cout<<"\n"<<x<<" "<<y;
    swap_noAux(x,y);
    cout<<"\n"<<x<<" "<<y;
}

//Blu-Color Compiler inc. All rights Reserved.
