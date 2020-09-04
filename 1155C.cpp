#include <bits/stdc++.h>

using namespace std;

int n,m;
long long a[300010];
long long b[300010];
vector<long long> v;
int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);

    for (int i = 0; i < m; ++i)
        scanf("%lld", b + i);
    
    for (int i = 1; i < n; ++i)
        v.push_back(a[i] - a[i - 1]);
    long long gcd = 0;
    
    for (int i = 0; i < (int)v.size(); ++i)
        gcd = __gcd(gcd, v[i]);

    for (int i = 0; i < m; ++i) {
        if(gcd % b[i] == 0) {
            printf("YES\n%lld %d\n", a[0], i + 1);
            return 0;
        }
    }
    puts("NO");
    return 0;
}

