#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return true;
    return false;    
}

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> result;
    // first window of size k;
    int cnt = 0;
    for(int i=0;i<k;i++) {
        if(isVowel(s[i]))
            cnt++;
    }
    result.push_back(cnt);

    // apply sliding window
    for(int i=k;i<n;i++) {
        if(isVowel(s[i-k]))
            cnt--; 
        if(isVowel(s[i]))    
            cnt++;
        result.push_back(cnt);
    }

    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";
}