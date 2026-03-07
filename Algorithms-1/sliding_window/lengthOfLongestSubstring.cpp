#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int l = 0, ans = 0;

    for(int r = 0; r < int(s.size()); r++)
    {
        while(st.count(s[r]))
        {
            st.erase(s[l]);
            l++;
        }

        st.insert(s[r]);
        ans = max(ans, r - l + 1);
    }

    return ans;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}