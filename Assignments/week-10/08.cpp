#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    bool found = false;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == x) {
            found = true;
            break;
        } else if(sum < x) {
            left++;
        } else
            right--;
    }

    if(found) 
        cout << "TRUE" << endl;
    else
        cout << "FALSE"  << endl;  
}