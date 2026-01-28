#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int,int> mp;   // prefix sum -> first index
        int sum = 0;
        int maxlen = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // Subarray from index 0 to i
            if(sum == k) {
                maxlen = i + 1;
            }
            else if(mp.find(sum - k) != mp.end()) {
                maxlen = max(maxlen, i - mp[sum - k]);// checking subarraysum 
                                                     //sum-k exists 
            }

            // Store first occurrence of prefix sum
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;// if i=2 subarraysum is 10 and 
                           //i=4 also then no need to store this 
                                
            }
        }
        return maxlen;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.longestSubarray(arr, k) << endl;

    return 0;
}
