#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long n,k; cin >> n >> k;
    long long mn = LLONG_MAX, id = -1, a = 0;;
    for (int i = 0; i < k; ++i) {
        long long x; cin >> x;
        long long cur = n % x;
        if(cur < mn) {
            mn = cur;
            id = i;
            a = x;
        }
    }

    cout << id + 1<< " " << n / a << "\n";
    return 0;
}

