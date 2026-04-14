#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;

    vector<int> arr(n);
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        mpp[arr[i]] = i;
    }



    while(q--) {
        int x;
        cin >> x;

        if(mpp.find(x) != mpp.end()) 
            cout<<mpp[x]+1<<endl;
        else
            cout<<-1<<endl;        
    }
}