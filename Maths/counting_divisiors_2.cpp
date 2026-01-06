#include<iostream>
#include<vector>
using namespace std;
const int maxi=1e6;
int arr[maxi+1];
int main()
{   //using of sieve of erotheses for making number poinr a prime
    for(int i=2;i<=maxi;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i;j<=maxi;j+=i) arr[j]=i;
        }
    }

    int n ;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int  div_count=1;
        while(x!=1){
        int prime=arr[x];
        int c=0;
        while(x%prime==0)
        {
            c++;
            x/=prime;

        }
        div_count*=c+1;
    }
    cout<<div_count<<" ";

    }
}