#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums)
{
    int idx = 0;
    int n = nums.size();

    // Find index of minimum element
    for (int i = 0; i < n; i++)
    {
        if (nums[idx] > nums[i])
            idx = i;
    }

    // Move left while equal elements exist
    int h = 0;
    while (nums[idx] == nums[(idx - 1 + n) % n] && h < n)
    {
        idx = (idx - 1 + n) % n;
        h++;
    }

    // Check if array is sorted in circular manner
    int k = 1;
    while (k < n && nums[idx] <= nums[(idx + 1) % n])
    {
        idx = (idx + 1) % n;
        k++;
    }

    return (k == n);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (check(nums))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
