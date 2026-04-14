#include<bits/stdc++.h>
using namespace std;

/*
    n = 5000 at max;
    so, O(n^3) will give TLE , 5000 * 5000 * 5000 = 125 * 10^9

    hence, need O(n^2), 5000 * 5000 = 25*10^6
    a[i] = 10^9 in worst case
    so, take long long as sum will go till 10^11
*/

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    // build prefix sum array
    vector<long long> p(n);
    p[0] = arr[0];
    for(int i=1;i<n;i++)
        p[i] = p[i-1] + arr[i];
    
    long long sum = 0;    
    for(int l=0;l<n;l++) {
        for(int r=l;r<n;r++) {
            if(l == 0)
                sum += p[r];
            else
                sum += p[r] - p[l-1];    
        }
    }

    cout << sum << "\n";
}