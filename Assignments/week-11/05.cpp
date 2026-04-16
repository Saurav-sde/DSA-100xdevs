#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin >> A[i];
    
    long long sum = 0;
    int maxLen = 0;
    int left = 0, right = 0;
    while(right < n) {
        sum += A[right];
        
        // shrink window
        while(sum >= k) {
            sum -= A[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << maxLen << endl;
}