#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<long long> prefix(n);

    // Build alternating prefix
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        if(i % 2 == 0)
            prefix[i] = prefix[i-1] + arr[i];
        else
            prefix[i] = prefix[i-1] - arr[i];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        l--; r--;

        long long ans;
        if(l == 0)
            ans = prefix[r];
        else
            ans = prefix[r] - prefix[l-1];

        // Adjust sign based on l
        if(l % 2 == 1)
            ans = -ans;

        cout << ans << '\n';
    }
}