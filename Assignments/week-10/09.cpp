#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int,int> mpp;
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    
    for(int i=0;i<n;i++) {
        int target = x - a[i];
        if(mpp.find(target) != mpp.end()) {
            cout << i+1 << " " << mpp[target] << endl;
            return 0;
        }
        mpp[a[i]] = i+1;
    }
    
    cout << "-1";
} 