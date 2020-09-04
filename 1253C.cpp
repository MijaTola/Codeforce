#include <bits/stdc++.h>

using namespace std;

int n,m;
long long v[200010];
vector<long long> sum[200010];
long long s[200010];
long long mul[200010];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
        scanf("%lld", v + i);

    sort(v, v + n);
    reverse(v, v + n);

    for (int i = 0; i < n; ++i) 
        sum[i % m].push_back(v[i]);

    
    long long cur = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0, k = 1; j < (int)sum[i].size(); ++j, k++) {
            mul[i] += sum[i][j] * (long long)k;
            s[i] += sum[i][j];
        }
        reverse(sum[i].begin(), sum[i].end());
        cur += mul[i];
    }

    
    vector<int> ans;
    ans.push_back(cur);

    for (int i = 0; i < n; ++i) {
        cur -= s[i % m];
        s[i % m] -= sum[i % m].back();
        sum[i % m].pop_back();
        ans.push_back(cur);
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (long long x: ans)
        printf("%lld ", x);

    puts("");
    
    return 0;
}

