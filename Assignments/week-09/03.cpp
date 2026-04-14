#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    
    vector<int> vowel(n);
    if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') 
        vowel[0] = 1;
    else    
        vowel[0] = 0;
    
    for(int i=1;i<s.size();i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            vowel[i] = vowel[i-1] + 1;
        else
            vowel[i] = vowel[i-1];
    }

    int q;
    cin >> q;

    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;

        if(l == 0)
            cout<<vowel[r]<<endl;
        else
            cout<<vowel[r] - vowel[l-1] << endl;     
    }
}