#include<bits/stdc++.h>
using namespace std;

int divisor(int n) {
    int cnt = 0;
    for(int i=1;i*i<=n;i++) {
        if(n % i == 0) {
            if(i * i == n)
                cnt = cnt + 1;
            else        
                cnt = cnt + 2;  
        }
    }

    return cnt;
}

int main() {
    int n,q,k;
    cin >> n >> q >> k;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    vector<int> prefix(n);
    if(divisor(arr[0]) == k)
        prefix[0] = 1;
    else
        prefix[0] = 0;
    
    for(int i=1;i<n;i++) {
        if(divisor(arr[i]) == k)
            prefix[i] = prefix[i-1] + 1;
        else
            prefix[i] = prefix[i-1];
    }
    
    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;

        if(l == 0)  
            cout << prefix[r] << endl;
        else
            cout << prefix[r] - prefix[l-1] << endl;
    }
}