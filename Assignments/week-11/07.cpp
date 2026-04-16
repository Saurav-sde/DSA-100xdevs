#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    int x = 0; // store no of unique characters in current window
    int maxLen = 0;
    unordered_map<char,int> mpp;
    int left = 0, right = 0;
    while(right < n) {
        mpp[s[right]]++;

        // if freq is 1 means a new unique character came
        if(mpp[s[right]] == 1)
            x++;
        
        // shrink window until no. of unqiue character is > k
        while(x > k) {
            mpp[s[left]]--;
            if(mpp[s[left]] == 0)
                x--;
            left++;    
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << maxLen << " ";
}