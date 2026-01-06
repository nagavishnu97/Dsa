#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int  n ;
    cin >>n;
    int c=0;
    for(int i =1;i*i<n;i++)
    {
        if(n%i==0)
        {
            c+=2;

        }
    }
   int r = sqrt(n);
    if(r*r==n) c++;
    cout<<c;
}