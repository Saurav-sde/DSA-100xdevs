#include<bits/stdc++.h>
using namespace std;

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
    
    for(int l=0;l<n;l++) {
        for(int r=l;r<n;r++) {
            if(l == 0)
                cout << p[r] << "\n";
            else
                cout << p[r] - p[l-1] << "\n";   
        }
    }
}