#include <bits/stdc++.h>

using namespace std;

int n;
int p[55];
long long ans[5];
vector<pair<int,int> > v;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", p + i);

    for (int i = 0; i < 5; ++i) {
        int x;
        scanf("%d", &x);
        v.emplace_back(x,i);
    }

    sort(v.rbegin(), v.rend());

    long long cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += p[i];
        for (int j = 0; j < 5; ++j) {
            if(cur >= v[j].first) {
                ans[v[j].second] += cur / v[j].first;
                cur %= v[j].first;
            }
        }
    }
    
    for (int i = 0; i < 5; ++i) 
        printf("%lld ", ans[i]);
    puts("");
    printf("%lld\n", cur);
    return 0;
}

