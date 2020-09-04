#include <bits/stdc++.h>

using namespace std;

set<long long> r,c;
int main() {
    
    long long n,m;
    cin >> n >> m;
    long long cur = n * n;
    while(m--) {
        long long x,y;
        cin >> x >> y;
        bool flag = 0;
        if(!r.count(x) or !c.count(y)) {
            if(!c.count(y)) 
                cur -= (n - r.size()), flag = 1;
            if(!r.count(x)) {
                cur = (cur - abs(n - (long long)c.size())) + flag;
                c.insert(y);
            }
            c.insert(y);
            r.insert(x);
        }
        c.insert(y);
        r.insert(x);
        cout << cur << "\n";
    }
    return 0;
}


