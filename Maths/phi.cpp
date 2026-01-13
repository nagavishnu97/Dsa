// Euler's totient function - written using phi φ(n)
// counts the number of positive integers in the interval [1, n]
// which are coprime to n.
//
// Two numbers a and b are coprime if their
// greatest common divisor is equal to 1, i.e. gcd(a, b) = 1.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    int ans=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            ans-=ans/i;

        }
    }
    if(n>1) ans-=ans/n; //if n==2,3,5,7,11 or any prime then for loop wont be useful
    cout<<ans;
}