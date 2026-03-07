#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int>& arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= arr[i])
            st.pop();

        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result = nextGreater(arr);

    cout << "Next Greater Elements:\n";
    for(int x : result)
        cout << x << " ";

    return 0;
}