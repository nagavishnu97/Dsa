#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int st, int mid, int end)
{
    vector<int>temp(end-st+1);
    int i=st;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
           
    }
    while(i<=mid) 
      temp[k++]=arr[i++];
    while(j<=end)
      temp[k++]=arr[j++];
    for(int i=0;i<k;i++)
    {
        arr[st+i]=temp[i];
    }
}
void mergeSort(vector<int>&arr,int st, int end)
{
    if(st<end)
    {
        int mid = st+(end-st)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
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
    mergeSort(arr,0,n-1);
    cout<<"Array After sorting "<<endl;
    for(int i:arr)
      cout<<i<<" ";

}