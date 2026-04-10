#include<bits/stdc++.h>
using namespace std;

void printSubarray(vector<int> &arr) {
    for(int i=0;i<arr.size();i++) {
        long long sum = 0;
        for(int j=i;j<arr.size();j++) {
            sum += arr[j];
            cout << sum << endl;   
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    printSubarray(arr);
}