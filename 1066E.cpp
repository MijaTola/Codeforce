#include <bits/stdc++.h>

using namespace std;

int n,m;
char x;
vector<int> a,b;
long long val[200010];
char da[200010];
char db[200010];
const int mod = 998244353;
void init() {
    long long p = 1;
    for (int i = 0; i < 200010; ++i) {
        val[i] = p;
        p = (p * 2) % mod;
    }
}
int main() {
    init();
    scanf("%d %d %s %s", &n, &m, da, db);

    for (int i = n - 1; i >= 0; --i)
        if(da[i] == '1') a.push_back(n - i - 1);

    for (int i = m - 1; i >= 0; --i)
        if(db[i] == '1') b.push_back(m - i - 1);
    
    long long ans = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        long long pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        long long total = b.size() - pos;
        long long p1 = a[i];
        ans = (ans + (total * val[p1]) % mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}

