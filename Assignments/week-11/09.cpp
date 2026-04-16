#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    
    unordered_map<int,int> mpp;
    int x = 0;
    long long cnt = 0;
    int left = 0, right = 0;
    while(right < n) {
        mpp[nums[right]]++;
        if(mpp[nums[right]] == 1)
            x++;
        
        while( x > k) {
            mpp[nums[left]]--;
            if(mpp[nums[left]] == 0)
                x--;
            left++;    
        }

        cnt += right - left + 1;
        right++;
    }

    cout << cnt << endl;
}