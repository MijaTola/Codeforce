#include <bits/stdc++.h>

using namespace std;

long long a[1010];
vector<int> v;

int main() {
    
    long long n,m;
    scanf("%lld %lld", &n, &m);

    for (int i = 1; i <= m; ++i)
        v.push_back((i * i) % m);

    long long cur = n / m;

    for (auto x: v)  {
        a[x] += cur;
    }

    for (int i = 0; i < n % m; ++i)
        a[v[i]]++;

    long long ans = 0;
    
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            if((i + j) % m == 0) 
                ans += a[i] * a[j];

    printf("%lld\n", ans);
    return 0;
}


