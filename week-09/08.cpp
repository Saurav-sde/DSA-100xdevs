#include<bits/stdc++.h>
using namespace std;

void printSubarray(vector<int> &arr) {
    for(int i=0;i<arr.size();i++) {
        vector<int> temp;
        for(int j=i;j<arr.size();j++) {
            temp.push_back(arr[j]);
            
            for(int k=0;k<temp.size();k++)
                cout << temp[k] << " ";
            cout << endl;    
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