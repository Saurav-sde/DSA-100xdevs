#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];

    int minLength = INT_MAX;
    long long sum = 0;
    int left = 0, right = 0;
    while(right < n) {
        sum += nums[right];

        while(sum > k) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }

        right++;
    }

    if(minLength == INT_MAX)
        cout << -1 << endl;
    else    
        cout << minLength << endl;
}