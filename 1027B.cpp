#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n,q;
    cin >> n >> q;
    long long even = (n + 1)/ 2;
    long long odd = n / 2;
    while(q--) {
        long long x,y;
        cin >> x >> y;   
        long long cur = (x + 1) / 2 * even +  x / 2 * odd;
        long long cur2 = (x + 1) / 2 * odd + x / 2 * even + (n * n + 1) / 2;
        if((x + y) % 2 == 0) {
            long long de = (n + !(n & 1)) / 2 - (y + !(n & 1)) / 2 ;
            cout << cur - de << "\n";
        } else {
            long long de = (n + !(n & 1)) / 2 - (y + !(n & 1)) / 2 ;
            cout << cur2 - de << "\n";
        }
    }
    return 0;
}

