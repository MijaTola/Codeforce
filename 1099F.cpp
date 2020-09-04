#include <bits/stdc++.h>

using namespace std;

int n;
long long t;
int cookies[100010];
int tim[100010];
long long dp[100010];
vector<pair<int,int> > G[200010];

struct SegmentTree {

    int n;
    vector<long long> st;

    SegmentTree() {}
    void build(int _) {
        n = _;
        st.resize(3 * n);
    }
    void update(int pos, long long value){
        for (st[pos += n] += value; pos > 1; pos>>=1)
            st[pos>>1] = st[pos] + st[pos^1]; 
    }
    // interval[l,r)
    long long query(int l,int r){
        long long ans = 0;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans += st[l++];
            if(r & 1) ans += st[--r];
        }
        return ans;
    }
};

SegmentTree st1,st2;

const int lim = 1e6;

void dfs(int u, long long t) {
    if(st1.query(0, lim) <= t) dp[u] = st2.query(0, lim);
    else {
        int a = 0, b = lim + 2;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(st1.query(0, mid) <= t) a = mid;
            else b = mid;
        }

        dp[u] = st2.query(0, a);
        long long left = t - st1.query(0, a);
        if(b <= lim) dp[u] += min(st2.query(b,b), left / b);
    }

    for (auto p: G[u]) {
        int v = p.first;
        int c = p.second;
        st1.update(tim[v], 1LL * tim[v] * cookies[v]);
        st2.update(tim[v], cookies[v]);
        dfs(v, t - 2 * c);
        st1.update(tim[v], -1LL * tim[v] * cookies[v]);
        st2.update(tim[v], -cookies[v]);
    }

}

long long f(int u) {
    
    priority_queue<long long> q;

    for (auto p: G[u]) {
        int v = p.first;
        q.push(f(v));
    }

    if(q.size() >= 2) {
        q.pop();
        dp[u] = max(dp[u], q.top());
    }

    return dp[u];
}

int main() {

    scanf("%d %lld", &n, &t);   
    
    st1.build(lim + 10);
    st2.build(lim + 10);
    for (int i = 1; i <= n; ++i)
        scanf("%d", cookies + i);

    for (int i = 1; i <= n; ++i)
        scanf("%d", tim + i);

    for (int i = 2; i <= n; ++i) {
        int p,l;
        scanf("%d %d", &p, &l);
        G[p].push_back({i,l});
    }
    
    st1.update(tim[1], 1LL * tim[1] * cookies[1]);
    st2.update(tim[1], cookies[1]);

    dfs(1, t);

    long long ans = dp[1];

    for (auto p: G[1]) 
        ans = max(ans, f(p.first));
    printf("%lld\n", ans);

    return 0;
}

