#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&arr,int st ,int end)
{
    int pivot=arr[end];
    int i=st;
    int j=st-1;//j is always before element greater than pivot
    //the aim is element is smaller than pivot should be left and greater should be right
    for(int i=st;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            swap(arr[j],arr[i]);
        }

    }
    j++;
    swap(arr[j],arr[end]);
    return j;
}
void QuickSort(vector<int>&arr,int st, int end)
{
    if(st<end)
    {
        int idx=partition(arr,st,end);
        QuickSort(arr,st,idx-1);
        QuickSort(arr,idx+1,end);
        
    }
}
int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++)
         cin>>arr[i];
    
    cout<<"Array before sorting "<<endl;
    for(int i:arr)
      cout<<i<<" ";
    QuickSort(arr,0,n-1);
    cout<<"Array After sorting "<<endl;
    for(int i:arr)
      cout<<i<<" ";

}