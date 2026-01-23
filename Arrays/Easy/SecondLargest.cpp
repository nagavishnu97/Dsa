#include<iostream>
#include<vector>
using namespace std;
int SecondLargest(vector<int>&arr)
{ // if largest and second largest is same then return -1
    int maxi = -1;
        int maxi2;
        for(int i:arr)
        {
            if(i>maxi)// test case 10,10,10 check this case to understand why this is written
            {
                maxi2=maxi;
                maxi=i;
            }
            else if(i>maxi2 && i!=maxi)
            {
                maxi2=i;//test case 10,5,10 check this case to understand why this is written
            }
        }
        return maxi2;
}
int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
       cin>>arr[i];
    cout<<SecondLargest(arr);
}