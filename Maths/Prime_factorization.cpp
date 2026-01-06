#include<iostream>
#include<vector>
using namespace std;
void prime_factor(int n , vector<int>&arr)
{
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            arr.push_back(i);
            n/=i;
        }
    }
    if(n>1) arr.push_back(n);
}
int main()
{
    int n ;
    cin>>n;
    vector<int>arr;
    prime_factor(n,arr);
    for(int i:arr)
    {
        cout<<i<<" ";
    }
}