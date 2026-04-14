#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;

    vector<long long> arr(n);
    long long totalSum = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    
    vector<long long> p(n);
    p[0] = arr[0];
    for(int i=1;i<n;i++)
        p[i] = p[i-1] + arr[i];

    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;

        if(l == 0) {
            if((totalSum - p[r]) % 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else {
            if((totalSum - p[r] - p[l-1]) % 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}