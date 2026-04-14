#include<bits/stdc++.h>
using namespace std;

long long totalDivisors(long long n) {
    long long cnt = 0;
    for(long long i=1;i*i <= n;i++) {
        if(n % i == 0) {
            long long f1 = i;
            long long f2 = n / i;
            if(f1 == f2)  {
                cnt++;
            }
            else
                cnt += 2;
        } 
            
    }

    return cnt;
}

int main() {
    long long a,b;
    cin >> a >> b;

    long long cntA = totalDivisors(a);
    long long cntB = totalDivisors(b);

    if(cntA > cntB)
        cout << "A" << endl;
    else if(cntB > cntA)    
        cout << "B" << endl;
    else
        cout << "DRAW" << endl;    
}