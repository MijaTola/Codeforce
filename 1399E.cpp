#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > G[100010];
int cnt[100010];

void dfs(int u, int p = -1) {
    if((int)G[u].size() <= 1 and u > 1) {
        cnt[u] = 1;
        return;
    }
    
    for (auto [v, w]: G[u]) {
        if(v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

void task1() {
    int n;
    long long s;
    cin >> n >> s;

    for (int i = 1; i <= n + 2; ++i) {
        G[i].clear();
        cnt[i] = 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
    
    dfs(1);
    long long sum = 0;
    priority_queue<tuple<long long,int, int,int> > q;
    set<pair<int,int> > st;
    for (int i = 1; i <= n; ++i) {
        if((int)G[i].size() <= 1 and i > 1) continue;
        for (auto [j,w]: G[i]) {
            if(j == i) continue;
            if(st.count({min(i,j), max(i,j)})) continue;
            st.insert({min(i,j), max(i,j)});
            sum += 1LL * w * cnt[j];
            int odd = w % 2 == 0;
            long long current = 1LL * w * cnt[j];
            long long dv = 1LL * (w / 2) * cnt[j];
            q.push({abs(current - dv), odd, -w, cnt[j]});   
        }
    }

    
    int ans = 0;

    while(!q.empty() and sum > s) {
        auto [cur, odd, w, l] = q.top();
        w = -w;
        ans++;
        q.pop();
        sum -= 1LL * w * l;;
        w /= 2;
        sum += 1LL * w * l;
        odd = (w % 2 == 0);
        long long current = 1LL * w * l;
        long long dv = 1LL * (w / 2) * l;
        if(w) q.push({abs(current - dv), odd, -w, l});
    }

    cout << ans << "\n";
}
int main() {

    int t;
    cin >> t;

    while(t--) {
        task1();
    }
    return 0;
}

