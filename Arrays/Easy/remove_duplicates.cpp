#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int j = 0;   // index of last unique element

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[j] != nums[i])
        {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;   // new length
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k = removeDuplicates(nums);

    // Print new length
    cout << k << endl;

    // Print array after removing duplicates
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";

    cout << endl;

    return 0;
}
