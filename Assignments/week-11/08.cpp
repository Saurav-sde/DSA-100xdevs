#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;    
    cin >> n >> k;

    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    
    long long cnt = 0;
    long long sum = 0;
    int left = 0, right = 0;
    while(right < n) {
        sum += nums[right];

        while(sum >= k) {
            sum -= nums[left];
            left++;
        }

        cnt += right - left + 1;
        right++;
    }     

    cout << cnt << endl;
}