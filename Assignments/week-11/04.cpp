#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k; 
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];

    vector<int> good(m);
    set<int> st;
    for(int i=0;i<m;i++) {
        cin >> good[i];
        st.insert(good[i]);
    }

    // count good numbers in first window of size k
    int cnt = 0;
    vector<int> ans;
    for(int i=0;i<k;i++) {
        if(st.find(nums[i]) != st.end())
            cnt++;
    }
    ans.push_back(cnt);


    // sliding window technique
    for(int i=k;i<n;i++) {
        if(st.find(nums[i-k]) != st.end())
            cnt--;
        if(st.find(nums[i]) != st.end())    
            cnt++;
        ans.push_back(cnt);    
    }


    for(int i=0;i<ans.size();i++)
        cout << ans[i] <<  " ";
}