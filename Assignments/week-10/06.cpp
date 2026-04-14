#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> s1;
    set<int> s2;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        s1.insert(a[i]);
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for(int i=0;i<m;i++) {
        cin >> b[i];
        s2.insert(b[i]);
    }

    vector<int> result;
    for(auto it:s1) {
        if(s2.find(it) != s2.end()) {
            result.push_back(it);
        }
    }

    cout << result.size() << endl;
    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";

}