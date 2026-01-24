#include <bits/stdc++.h>
using namespace std;

void leftRotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    //<-- left
    reverse(arr.begin(), arr.begin() + k);// here [a,b) b is not included
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    leftRotate(arr, k);

    for (int x : arr)
        cout << x << " ";

    return 0;
}
