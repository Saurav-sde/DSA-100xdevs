#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;
    vector<pair<int,int>> p(n);
    if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'A' || s[0] == 'E' || s[0] == 'O' || s[0] == 'U') 
        p[0] = {1,0};
    else
        p[0] = {0,1};    
    
    for(int i=1;i<n;i++) {
        int prevVol = p[i-1].first;
        int prevCon = p[i-1].second;
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            p[i] = {prevVol + 1, prevCon};
        } else {
            p[i] = {prevVol, prevCon + 1};
        }
    }



    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;

        if(l == 0) {
            pair<int,int> temp = p[r];
            if(temp.first == temp.second)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            pair<int,int> temp1 = p[r];
            pair<int,int> temp2 = p[l-1];

            if(temp1.first - temp2.first == temp1.second - temp2.second)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}