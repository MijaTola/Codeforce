#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[200010];
long long a[200010];
bool ver(long long cur) {
    int pos = upper_bound(v, v + n, cur) - v;
    pos--;
    long long d = cur - v[pos];
    if(k < 0) return 0;
    int mid = (n + 1) / 2 - 1;
    if(pos < mid) return 1;
    long long dif = pos - mid;
    long long total = dif * cur;
    long long sum = a[pos - 1] - a[mid - 1];
    total -= sum;
    return k >= total + d and k >= 0;   
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(v, v + n);
    for (int i = 1; i < n; ++i)
        a[i] += (a[i - 1] + v[i]);

    
    long long a = 0, b = 1e12;
    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    cout << a << "\n"; 
    return 0;
}

