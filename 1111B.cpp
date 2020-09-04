#include <bits/stdc++.h>

using namespace std;

long long v[100010];

int main() {
    long long n,k,m;
    cin >> n >> k >> m;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    sort(v, v + n);
    long double ans = 0.0;
    long double sum = 0;   
    for (int i = 0; i < n; ++i)  {
        ans += v[i];
        sum += v[i];
    }

    for (int i = 1; i < n; ++i) 
        v[i] += v[i - 1];

    long double aux = sum;
    ans /= n;
    
    long double to = min(n * k, m);
    ans = max(ans, (aux + to) / n);
    for (int i = 0; i < min(n - 1, m); ++i) {
        long double toin = k * (n - (i + 1));
        long double total = min(toin, (long double)m - (i + 1));
        sum = aux - v[i];
        sum += total;
        ans = max(ans, sum / (n - (i + 1)));
    }

    cout.precision(10);
    cout<< fixed << ans <<"\n";
    return 0;
}

