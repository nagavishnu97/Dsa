#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size();

        long long sum = 1LL * (n + 1) * (n + 2) / 2;

        for (int x : arr) {
            sum -= x;
        }

        return (int)sum;
    }
};

int main() {
    int n;
    cin >> n;               // size of array (n)

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.missingNum(arr) << endl;

    return 0;
}

//above is my approch overflow proof approch is below
/*class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for (int i = 1; i <= n + 1; i++)
            ans ^= i;

        for (int x : arr)
            ans ^= x;

        return ans;
    }
};
*/