#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    vector<int> ans(n);
    unordered_map<int,int> freq;

    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
        ans[i] = freq.size();
    }

    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
}