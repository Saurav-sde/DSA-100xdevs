#include<bits/stdc++.h>
using namespace std;

long long sumOfMaxSubarrayOfSizeK(vector<int> &arr, int k) {
    int n = arr.size();
    long long maxSum = LLONG_MIN;
    long long sum = 0;
    int left = 0, right = 0;    
    while(right < n) {
        sum += arr[right];

        // shrink the window as it exceeds the limit k
        if(right - left + 1 > k) {
            sum -= arr[left];
            left++;
        }

        // update the maxSum when window size is exactly k
        if(right - left + 1 == k) {
            maxSum = max(maxSum, sum);
        } 
        right++;              
    }

    return maxSum;
}

long long sumOfMaxSubarrayOfSizeK2(vector<int>&arr, int k) {
    int n = arr.size();
    long long sum = 0;

    // Step 1: first window
    for(int i = 0; i < k; i++)
        sum += arr[i];

    long long maxSum = sum;

    // Step 2: slide window
    for(int i = k; i < n; i++) {
        sum += arr[i];        // add new
        sum -= arr[i-k];      // remove old
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}


int main() {
    int n,k;
    cin >> n >> k;

    // there is no subarray of size k 
    if(k > n)
        cout << 0 << endl;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    cout << sumOfMaxSubarrayOfSizeK2(arr, k) << endl;
}
