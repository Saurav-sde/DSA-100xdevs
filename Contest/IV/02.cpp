#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    int maxCnt = 0, cnt = 1;
    for(int i=0;i<n-1;i++) {
        if(arr[i] == arr[i+1]) 
            cnt++;
        else {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
        }    
    }
    maxCnt = max(maxCnt, cnt);

    cout << maxCnt << endl;
}