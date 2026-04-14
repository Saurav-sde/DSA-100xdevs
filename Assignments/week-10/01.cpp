#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int,int> mpp;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    int cnt = 0;
    for(auto it: mpp) 
        cnt++;

    cout << cnt << "\n";
}