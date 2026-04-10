#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    int n,q,k;
    cin >> n >> q >> k;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin >> arr[i];

    vector<int> prefix(n);
    if(sumOfDigits(arr[0]) == k)
        prefix[0] = 1;
    else
        prefix[0] = 0;
    
    for(int i=1;i<n;i++) {
        if(sumOfDigits(arr[i]) == k)
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