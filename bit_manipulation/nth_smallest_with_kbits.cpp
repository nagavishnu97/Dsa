#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long c(int m, int k) {
        if (k > m) return 0;
        if (k == m - 1 || k == 1) return m;
        if (k == m || k == 0) return 1;

        long long ans = 1;
        if (k > m - k) k = m - k;

        for (int i = 0; i < k; i++) {
            ans *= (m - i);
            ans /= (i + 1);
        }
        return ans;
    }

    long long nthSmallest(long long n, int k) {
        if (k == 0) return 0;
        if (k == 1) return (1LL << (n - 1));

        int m = k;
        while (c(m, k) < n)
            m++;

        long long ans = 1LL << (m - 1);
        n -= c(m - 1, k);
        k--;

        for (int i = m - 2; i >= 0 && k > 0; i--) {
            long long cnt = c(i, k);
            if (cnt < n) {
                ans += 1LL << i;
                n -= cnt;
                k--;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    long long n;
    int k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << "Nth smallest number with " << k << " set bits = "
         << obj.nthSmallest(n, k) << endl;

    return 0;
}
