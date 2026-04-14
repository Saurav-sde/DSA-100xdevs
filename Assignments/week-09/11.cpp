#include<bits/stdc++.h>
using namespace std;

/*
    n = 100 at max;
    so, O(n^3) will work 
    100 * 100 * 100 = 10^6

    a[i] = 10^9 in worst case
    so, take long long as sum will go till 10^11
*/

long long sumOfAllSubarrays(vector<int> &arr) {
    int n = arr.size();
    long long totalSum = 0;
    for(int l=0;l<n;l++) {
        for(int r=l;r<n;r++) {
            for(int i=l;i<=r;i++) {
                totalSum += arr[i];
            }
        }
    }

    return totalSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) 
        cin >> arr[i];
    
    cout << sumOfAllSubarrays(arr) << "\n";
}