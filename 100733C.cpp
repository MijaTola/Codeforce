#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    unsigned long long t = 0;
    unsigned long long p = 100;
    int flag = 0;
    while(s.back() == '0') s.pop_back();

    for (char x: s) {
        if(x == '.') {
            flag = 1;
            continue;
        }
        t = t * 10 + (x - '0');
        if(flag) p *= 10;
    }

    unsigned long long gcd = __gcd(t,p);
    if(gcd == 1) {
        cout << p << "\n";
        return 0;
    }
    
    long double val = t / gcd;
    cout.precision(0);
    cout << fixed << (val / t) * p << "\n";
    return 0;
}

