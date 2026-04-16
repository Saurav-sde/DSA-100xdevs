#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char,int> mpp;
    int maxLen = 0;
    int left = 0, right = 0;
    while (right < n) {
        mpp[s[right]]++;

        while(mpp[s[right]] > 1) {
            mpp[s[left]]--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << maxLen << " ";
}