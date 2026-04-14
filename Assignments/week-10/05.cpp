#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> st;
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for(int i=0;i<m;i++) {
        cin >> b[i];
        st.insert(b[i]);
    }

    cout << st.size() << endl;
    for(auto it:st)
        cout << it << " ";
}