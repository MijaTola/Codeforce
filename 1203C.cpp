#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    long long gcd = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        gcd = __gcd(x, gcd);
    }
    set<long long> s;
    for (long long i = 1; i * i <= gcd; ++i) {
        if(gcd % i == 0) {
            s.insert(gcd / i);
            s.insert(i);
        }
    }
    cout << s.size() << "\n";
    return 0;
}

