#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int,long long> mpp;
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    
    long long cnt = 0;
    for(int i=0;i<n;i++) {
        int target = x - a[i];
        if(mpp.find(target) != mpp.end()) {
            cnt += mpp[target];
        }
        mpp[a[i]]++;
    }
    
    cout << cnt << endl;
} 