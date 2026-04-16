#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin >> A[i];
    
    unordered_map<int,int> mpp;
    vector<int> ans;
    
    int cnt = 0;
    for(int i=0;i<k;i++) {
        if(mpp[A[i]] == 0)
            cnt++;
        mpp[A[i]]++;    
    }
    ans.push_back(cnt);

    // apply sliding window
    for(int i=k;i<n;i++) {
        mpp[A[i-k]]--;
        if(mpp[A[i-k]] == 0) {
            cnt--;
        }

        mpp[A[i]]++;
        if(mpp[A[i]] == 1)
            cnt++;
        
        ans.push_back(cnt);
    }

    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
}