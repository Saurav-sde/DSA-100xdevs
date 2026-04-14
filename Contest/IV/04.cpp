#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    long long totalSum = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    long long prefixSum = 0;
    int cnt = 0;

    for(int i=0;i<n;i++) {
        prefixSum += arr[i];
        if(2 * prefixSum == totalSum + arr[i])
            cnt++;
    }

    cout << cnt << endl;
}