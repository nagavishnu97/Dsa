#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int cnt = 0;
    int sum = 0;
    unordered_map<int,int> mp;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if(sum == k)
            cnt++;

        if(mp.find(sum - k) != mp.end()) {
            cnt += mp[sum - k];
        }

        mp[sum]++;
    }

    return cnt;
}

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target sum k: ";
    cin >> k;

    int result = subarraySum(nums, k);

    cout << "Number of subarrays with sum = " << k << " is: " << result << endl;

    return 0;
}
