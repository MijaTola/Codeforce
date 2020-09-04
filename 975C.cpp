#include <bits/stdc++.h>

using namespace std;

long long v[200100];
long long n,q; 

int bs(long long x, long long cur) {
    int a = 0;
    int b = n + 1;
    while(b - a > 1) {
        int mid = (a + b) >> 1;
        if(cur + x >= v[mid])  a = mid;
        else b = mid;
    }
    return a;
}
int main(){
    
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    for (int i = 1; i <= n; ++i)
        v[i] += v[i - 1];

    long long cur = 0;
    
    while(q--) {
        long long x; cin >> x;
        int pos = bs(x, cur);   
        if(pos + 1 <= n) {
            cout << n - (pos) << "\n";
            x -= v[pos];
            cur += x + v[pos];
        }else {
            cur = 0;
            cout << n << "\n";
        }
    }
    return 0;
}

