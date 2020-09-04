#include <bits/stdc++.h>

using namespace std;

int n,k;
long long a[100010], b[100010];

bool ver(long long x) {
    long long dk = k;
    for (int i = 0; i < n; ++i) {
        long long cur = a[i] * x;
        if(cur > b[i]) {
            long long dif = cur - b[i];
            if(dk < dif) return 0;
            dk -= dif;
        }
    }
    return 1;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];
    
    long long a = 0, b = 1e10 + 1;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    cout << a << "\n";
    return 0;
}

