#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int,int> freq1;
    map<int,int> freq2;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        freq1[a[i]]++;
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for(int i=0;i<m;i++) {
        cin >> b[i];
        freq2[b[i]]++;
    }

    vector<int> result;
    for(auto it1 : freq1) {
        int it2 = freq2[it1.first];
        int mini = min(it1.second, it2);
        while(mini--) {
            result.push_back(it1.first);
        }
    }

    cout << result.size() << endl;
    for(int i=0;i<result.size(); i++) {
        cout << result[i] << " ";
    }
}