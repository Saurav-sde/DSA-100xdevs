#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    // first window of size k
    long long maxSum = LONG_MIN;
    long long sum = 0;
    for(int i=0;i<k;i++)
        sum += arr[i];
    maxSum = sum;
    
    // appply sliding window
    int left = 0;
    int right = k;
    while(right < n) {
        sum -= arr[left++];
        sum += arr[right++];
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;
}