#include <bits/stdc++.h>

using namespace std;

int n,q;
int v[200010];
int p[200010];
int pl[200010];
int pr[200010];
int mx[200010];
int l[200010];
int r[200010];
int cnt[200010];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]);}
void merge(int x, int y) { p[find(y)] = find(x);} 
void init() { for (int i = 0; i < 200010; ++i) p[i] = i, l[i] = 1e9, pl[i] = 1e9;}

int main() {
    init();
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        cnt[v[i]]++;
        l[v[i]] = min(l[v[i]], i);
        r[v[i]] = max(r[v[i]], i);
    }
    
    int pos = 0;
    while(pos < n) {
        int dr = r[v[pos]];
        int cur = v[pos];
        for (;pos < dr and pos < n; ++pos) {
            merge(cur, v[pos]);
            dr = max(dr, r[v[pos]]);
            pl[cur] = min(pl[cur], l[v[pos]]);
            pr[cur] = max(pr[cur], r[v[pos]]);
            mx[cur] = max(mx[cur], cnt[v[pos]]);
        }
        pos++;
    }


    int ans = 0;
    for (int i = 1; i < 200010; ++i) {
        if(p[i] != i) continue;
        int total = pr[i] - pl[i] + 1;
        int cur = mx[i];
        if(cur == 0) continue;
        ans += total - cur;
    }
    cout << ans << "\n";

    return 0;
}

