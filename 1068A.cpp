#include <bits/stdc++.h>

using namespace std;

long long n,m,k,l;

int ver(long long x) {
    return x * m <= n and x * m - k >= l;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k >> l;
    if(m > n) return cout << "-1\n",0;
    long long a = 0;
    long long b = n / m;
    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    if(!ver(b)) puts("-1");
    else cout << b << "\n";
    return 0;
}

