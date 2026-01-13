#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    vector<int>phi(n+1,1);
    for(int i=2;i<=n;i++) phi[i]=i;
   
   
    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i) // i is prime
        {
            for(int j=i;j<=n;j+=i) phi[j]-=phi[j]/i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<phi[i]<<endl; 
    }


}