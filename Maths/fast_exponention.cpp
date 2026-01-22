#include <iostream>
using namespace std;

const long long p = 1000000007;

long long power(long long a, long long b)
{
    a %= p;                 // bring a under modulo
    long long ans = 1;

    while (b > 0)
    {
        if (b & 1)          // if b is odd
            ans = (ans * a) % p;

        a = (a * a) % p;    // square the base
        b >>= 1;            // divide b by 2
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        cout << power(a, b) << endl;
    }
}
