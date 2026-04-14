
#include <bits/stdc++.h>
using namespace std;

// 1. to LowerCase (https://leetcode.com/problems/to-lower-case/)
string toLowerCase(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] = s[i] + 32;
    }

    return s;
}

// 2. Palindrome Number (https://leetcode.com/problems/palindrome-number/)
bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int n = x;
    long long reverse = 0;
    while (n)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return x == reverse;
}

// 3. Max Consecutive Ones (https://leetcode.com/problems/max-consecutive-ones/)
// link:-
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxCnt = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            maxCnt = max(maxCnt, cnt);
            cnt = 0;
        }
    }
    maxCnt = max(maxCnt, cnt);
    return maxCnt;
}

// 4. Find Numbers with Even Number of Digits (https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/)
int findNumbers(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int digit = log10(nums[i]);
        if ((digit + 1) % 2 == 0)
            cnt++;
    }
    return cnt;
}

// 5. [Shuffle the Array - LeetCode](https://leetcode.com/problems/shuffle-the-array/)
vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        ans.push_back(nums[i]);
        ans.push_back(nums[i + n]);
    }

    return ans;
}

// 6. [Merge Strings Alternately - LeetCode](https://leetcode.com/problems/merge-strings-alternately/)
string mergeAlternately(string word1, string word2)
{
    int i = 0;
    int j = 0;

    string s = "";
    while (i < word1.size() && j < word2.size())
    {
        s += word1[i];
        i++;
        s += word2[j];
        j++;
    }

    while (i < word1.size())
    {
        s += word1[i];
        i++;
    }

    while (j < word2.size())
    {
        s += word2[j];
        j++;
    }

    return s;
}

// 7. [Monotonic Array - LeetCode](https://leetcode.com/problems/monotonic-array/)
bool isIncreasing(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            return false;
    }

    return true;
}

bool isDecreasing(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] < nums[i + 1])
            return false;
    }

    return true;
}

bool isMonotonic(vector<int> &nums)
{
    if (isIncreasing(nums) || isDecreasing(nums))
        return true;
    return false;
}

// 8. [Richest Customer Wealth - LeetCode](https://leetcode.com/problems/richest-customer-wealth/)
int maximumWealth(vector<vector<int>> &accounts)
{
    int maxWealth = 0;

    for (int i = 0; i < accounts.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < accounts[i].size(); j++)
            sum += accounts[i][j];

        maxWealth = max(maxWealth, sum);
    }

    return maxWealth;
}

// 9. [Pangrams | HackerRank](https://www.hackerrank.com/challenges/pangrams/problem)
string pangrams(string s)
{
    for (int i = 65; i <= 90; i++)
    {
        bool found = false;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == i || s[j] == i + 32)
            {
                found = true;
                break;
            }
        }

        if (found == false)
            return "not pangram";
    }

    return "pangram";
}

// 10. [Reverse Words | Practice | GeeksforGeeks](https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1)
string reverseWords(string &s)
{

    int n = s.size();
    string ans = "";

    string word = "";
    int i = n - 1;
    while (s[i] == '.')
        i--;

    int j = 0;
    while (s[j] == '.')
        j++;

    while (i >= j)
    {
        if (s[i] == '.')
        {
            reverse(word.begin(), word.end());
            ans += word;
            ans += '.';
            word = "";

            while (s[i] == '.')
                i--;
        }
        else
        {
            word += s[i];
            i--;
        }
    }

    reverse(word.begin(), word.end());
    ans += word;

    return ans;
}