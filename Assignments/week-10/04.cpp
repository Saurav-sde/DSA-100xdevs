#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    multiset<int> ms;
    unordered_map<int, int> freq;
    int distinct = 0;
    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            // insert x
            int x;
            cin >> x;
            ms.insert(x);
            freq[x]++;
            if(freq[x] == 1)
                distinct++;

        } else if(type == 2) {
            // remove one occurrence of x
            int x;
            cin >> x;

            auto it = ms.find(x);
            if(it != ms.end()) 
                ms.erase(it);

            if(freq[x] > 0) {
                freq[x]--;

                if(freq[x] == 0) 
                    distinct--;
            }

        } else if(type == 3) {
            // print count of distinct elements
            cout << distinct << endl;
        } else if(type == 4) {
            // check x is present or not
            int x;
            cin >> x;

            if(ms.find(x) != ms.end())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;    
        }
    }

}