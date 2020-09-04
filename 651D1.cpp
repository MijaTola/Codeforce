#include <bits/stdc++.h>

using namespace std;

string s;
int n,a,b,t;
long long l[2 * 500010];

bool ver(int k) {
    long long dis = (k - 1) * a;
    for (int i = n / 2 - k + 1; i <= n / 2 ; ++i) {
        long long ans = (min(abs(n / 2 - i + 1), abs(i + k - n / 2)) - 1) * a + dis;
        ans += l[i + k - 1];
        if(i) ans -= l[i - 1];
        if(ans <= t) return 1;
    }
    if(k == 1) return l[n / 2] - l[n / 2 - 1] <= t;
    return 0;   
}

int main() {
    cin >> n >> a >> b >> t >> s;
    s += s;
    n = 2 * n;
    for (int i = 0; i < n; ++i) 
        l[i] = (s[i] == 'w') ? 1 + b : 1;
    for (int i = 1; i < n; ++i)
        l[i] += l[i - 1];
    int a = 0, b = n / 2 + 1;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    cout << a << "\n"; 
    return 0;
}

