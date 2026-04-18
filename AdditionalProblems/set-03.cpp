#include<bits/stdc++.h>
using namespace std;

// 1. Contains Duplicate (https://leetcode.com/problems/contains-duplicate/description/)
bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x : nums)
            freq[x]++;

        for(auto it : freq) {
            if(it.second > 1)
                return true;
        }    

        return false;
    }

// 2. Valid Anagram (https://leetcode.com/problems/valid-anagram/description/)   
bool isAnagram(string s, string t) {
        vector<int> freq(26,0);

        for(char ch : s)
            freq[ch - 'a'] += 1;

        for(char ch : t) {
            freq[ch - 'a'] -= 1;
            if(freq[ch - 'a'] < 0)
                return false;
        }

        for(int i=0;i<26;i++)
            if(freq[i] > 0)
                return false;

        return true;
    }
    
// 3. Mex (https://atcoder.jp/contests/abc245/tasks/abc245_b)
// TC = O(N), SC = O(N)
int findFirstMissingNonNegative(vector<int> &nums) {
    int n = nums.size();
    vector<int> freq(n,0);

    for(int i=0;i<n;i++) {
        if(nums[i] >=0 && nums[i] < n)
            freq[nums[i]]++;
    }

    for(int i=0;i<n;i++) {
        if(freq[i] == 0)
            return i;
    }

    return n;
}

// TC = O(N), SC = O(1)
int findFirstMissingNonNegative(vector<int> &nums) {
    int n = nums.size();

    bool contains0 = false;
    for(int i=0;i<n;i++) {
        if(nums[i] == 0)
            contains0 = true;
        
        // replace -ve and out of range values
        if(nums[i] < 0 || nums[i] >= n)
            nums[i] = 0;
    }

    // mark presence, -ve indicates the value is present
    for(int i=0;i<n;i++) {
        nums[abs(nums[i])] = -abs(nums[abs(nums[i])]);
    }

    // if 0 is not present
    if(!contains0)
        return 0;

    // get the first missing
    for(int i=1;i<n;i++) {
        if(nums[i] > 0)
            return i;
    }

    return n;
}

// TC = O(N), SC = O(1)
int findFirstMissingNonNegative(vector<int> &nums) {
    int n = nums.size();

    bool contains0 = false;

    // Step 1: Check if 0 exists
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0)
            contains0 = true;

        // Replace negative and out-of-range values
        if(nums[i] < 0 || nums[i] >= n)
            nums[i] = 0;
    }

    // Step 2: Mark presence
    for(int i = 0; i < n; i++) {
        int val = nums[i] % n;   // important trick
        nums[val] += n;
    }

    // Step 3: If 0 not present
    if(!contains0)
        return 0;

    // Step 4: Find first missing
    for(int i = 1; i < n; i++) {
        if(nums[i] / n == 0)
            return i;
    }

    return n;
}


// 4. First Unique Character in a String (https://leetcode.com/problems/first-unique-character-in-a-string/description/)
int firstUniqChar(string s) {
        unordered_map<char,int> freq;

        for(int i=0;i<s.size();i++) {
            if(freq.find(s[i]) != freq.end()) {
                freq[s[i]] = -1;
            }
            else
                freq[s[i]] = i;
        }

        int ans = INT_MAX;
        for(auto it : freq) {
            if(it.second != -1) {
                ans = min(ans, it.second);
            }
        }

        if(ans == INT_MAX)
            return -1;
        return ans;    
    }

// 5. poll (https://atcoder.jp/contests/abc155/tasks/abc155_c)
vector<string> mostNumberOfVotes(vector<string> &s) {
    int n = s.size();

    // store the frequency of each string
    int maxCnt = 0;
    unordered_map<string,int> mpp;
    for(int i=0;i<n;i++) {
        mpp[s[i]]++;
        maxCnt = max(maxCnt, mpp[s[i]]);
    }
    
    // store all the strings whose frequency = maxCnt
    vector<string> ans;
    for(auto it : mpp) {
        if(it.second == maxCnt)
            ans.push_back(it.first);
    }

    // sort as we want in lexicographical order
    sort(ans.begin(), ans.end());
    
    return ans;
}

// 6. Isomorphic Strings (https://leetcode.com/problems/isomorphic-strings/description/)


// 7. Count Interval (https://atcoder.jp/contests/abc233/tasks/abc233_d)
long long countInterval(vector<int> &nums, long long k) {
    int n = nums.size();
    unordered_map<long long, int> mpp;
    long long pre = 0;
    long long cnt = 0;
    for(int i=0;i<n;i++) {
        pre += nums[i];

        if(pre == k)
            cnt++;
        
        if(mpp.find(pre - k) != mpp.end()) 
            cnt += mpp[pre - k];

        mpp[pre]++;
    }

    return cnt;
}

// 8. Contiguous Array (https://leetcode.com/problems/contiguous-array/description/)
int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> f;
        f[0] = -1;
        int cnt = 0, maxLen = 0;
        for(int i=0;i<nums.size();i++) {
            cnt =  cnt + (nums[i] == 0 ? -1 : 1);
            if(f.find(cnt) != f.end()) {
                maxLen = max(maxLen, i - f[cnt]);
            }
            else
                f[cnt] = i;

        }

        return maxLen;
    }

// 9. Same Difference (https://codeforces.com/problemset/problem/1520/D)
long long countSameDiff(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int,int> mpp;
    long long cnt = 0;

    for(int i=0;i<n;i++) {
        int val = nums[i] - i;
        if(mpp.find(val) != mpp.end())
            cnt += mpp[val];
        mpp[val]++;    
    }

    return cnt;
}



// 10. Count Number of Bad Pairs (https://leetcode.com/problems/count-number-of-bad-pairs/)
long long countBadPairs(vector<int>& nums) {
        long long badPairCount = 0;
        unordered_map<int,int> diffCount;

        for(int i=0;i<nums.size();i++) {
            int diff = i - nums[i];

            // check either this diff already came or not
            // if came means it will be good pair
            int goodPairCount = diffCount[diff];

            // badPair = totalPair - goodPair;
            badPairCount += i - goodPairCount;

            diffCount[diff] = goodPairCount + 1;
        }

        return badPairCount;
    }