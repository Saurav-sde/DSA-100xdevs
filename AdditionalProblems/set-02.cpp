#include <bits/stdc++.h>
using namespace std;

// 1. Cream puff (https://atcoder.jp/contests/abc180/tasks/abc180_c)
int main()
{
    long long n;
    cin >> n;

    vector<long long> divisor;
    int totalFactors = 0;

    for (long long i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            divisor.push_back(i);
            if (i == n / i)
                totalFactors++;
            else
                totalFactors += 2;
        }
    }

    for (int i = divisor.size() - 1; i >= 0; i--)
    {
        if (divisor[i] == n / divisor[i])
            continue;
        else
            divisor.push_back(n / divisor[i]);
    }

    for (int i = 0; i < divisor.size(); i++)
        cout << divisor[i] << "\n";
}

// 2.Four Divisors - (https://leetcode.com/problems/four-divisors/)
int sumOfDivisor(int n)
{
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                cnt++;
                sum += i;
            }
            else
            {
                sum += i;
                sum += n / i;
                cnt += 2;
            }
        }
    }

    if (cnt == 4)
    {
        return sum;
    }

    return 0;
}

int sumFourDivisors(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += sumOfDivisor(nums[i]);
    }

    return sum;
}

// 3. The kth Factor of n - (https://leetcode.com/problems/the-kth-factor-of-n/description/)
int kthFactor(int n, int k)
{
    vector<int> divisor;

    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            divisor.push_back(i);
        }
    }

    int x = divisor.size();
    for (int i = x - 1; i >= 0; i--)
    {
        if (n % divisor[i] == 0)
        {
            if (divisor[i] == n / divisor[i])
            {
                continue;
            }
            else
            {
                divisor.push_back(n / divisor[i]);
            }
        }
    }

    if (divisor.size() < k)
        return -1;
    return divisor[k - 1];
}

int kthFactor(int n, int k)
{

    // count total divisor
    int cnt = 0;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
                cnt++;
            else
                cnt += 2;
        }
    }

    // simply track the kth divisor
    if (cnt < k)
        return -1;

    int x = 0;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            x++;
            if (k == x)
                return i;
            if (k == cnt + 1 - x)
                return n / i;
        }
    }

    return -1;
}

// 4. Shift only  (https://atcoder.jp/contests/abc081/tasks/abc081_b)
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;
    for (int j = 0; j <= 30; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2)
            {
                cout << cnt << "\n";
                return 0;
            }
            else
                arr[i] = arr[i] / 2;
        }
        cnt++;
    }

    return 0;
}

// 5. Complete Prime Number - (https://leetcode.com/problems/complete-prime-number/)
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int reverse(int n)
{
    int rev = 0;
    while (n)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool completePrime(int num)
{
    int n = num;

    while (n)
    {
        if (!isPrime(n))
            return false;
        n /= 10;
    }

    n = reverse(num);
    while (n)
    {
        if (!isPrime(reverse(n)))
            return false;
        n /= 10;
    }

    return true;
}

// 6. Count Vowel Strings in Ranges - (https://leetcode.com/problems/count-vowel-strings-in-ranges/description/)
bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    int n = words.size();

    // calculate prefix sum array
    vector<int> p(n);
    if (isVowel(words[0][0]) && isVowel(words[0][words[0].size() - 1]))
        p[0] = 1;
    else
        p[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1]))
            p[i] = p[i - 1] + 1;
        else
            p[i] = p[i - 1];
    }

    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];

        if (l == 0)
            ans.push_back(p[r]);
        else
            ans.push_back(p[r] - p[l - 1]);
    }
    return ans;
}

// 7. Maximum Number of Vowels in a Substring of Given Length (https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)
bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

int maxVowels(string s, int k)
{
    int n = s.size();
    int maxCnt = 0;
    int cnt = 0;

    // first window of k size
    for (int i = 0; i < k; i++)
    {
        if (isVowel(s[i]))
            cnt++;
    }
    maxCnt = max(maxCnt, cnt);

    // apply sliding window technique
    int left = 0;
    int right = k;
    while (right < n)
    {
        if (isVowel(s[left]))
            cnt--;
        if (isVowel(s[right]))
        {
            cnt++;
            maxCnt = max(maxCnt, cnt);
        }
        left++;
        right++;
    }

    return maxCnt;
}

// 8. LeetCode Maximum Average Subarray I - (https://leetcode.com/problems/maximum-average-subarray-i/)
double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();
    double maxSum = -4001;

    // first window of size k
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    maxSum = sum;

    // apply sliding window technique
    int left = 0;
    int right = k;
    while (right < n)
    {
        sum -= nums[left++];
        sum += nums[right++];
        maxSum = max(maxSum, sum);
    }

    return maxSum / k;
}

// 9. LeetCode Sum of Even Numbers After Queries - (https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/)
vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int m = queries.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
            sum += nums[i];
    }

    vector<int> result(m);
    for (int i = 0; i < m; i++)
    {
        int idx = queries[i][1];
        int val = queries[i][0];

        if (nums[idx] % 2 == 0)
            sum -= nums[idx];
        nums[idx] += val;
        if (nums[idx] % 2 == 0)
            sum += nums[idx];
        result[i] = sum;
    }

    return result;
}

// 10. GeT AC (https://atcoder.jp/contests/abc122/tasks/abc122_c)
int main()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    // compute prefix array
    vector<int> p(n);
    p[0] = 0;
    if (s[0] == 'A' && s[1] == 'C')
        p[1] = 1;
    else
        p[1] = 0;

    for (int i = 2; i < n; i++)
    {
        if (s[i - 1] == 'A' && s[i] == 'C')
            p[i] = p[i - 1] + 1;
        else
            p[i] = p[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        if (l == 0)
            cout << p[r] << endl;
        else
            cout << p[r] - p[l] << endl;
    }
}