#include <bits/stdc++.h>

using namespace std;



struct SegmentTree {

    int n;
    vector<int> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(4 * _, 0);
        n = _;
    }

    int op(int a, int b) {
        return a + b;
    }
    void update(int pos,int value){
        for (st[pos += n] = value; pos > 1; pos>>=1)
            st[pos>>1] = op(st[pos], st[pos ^ 1]);
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = 0;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans = op(ans, st[l++]);
            if(r & 1) ans = op(ans, st[--r]);
        }
        return ans;
    }
};

SegmentTree s,wt,bl;
set<int> black, white;
int n;
int pos = 1;
int a[300010];
int b[300010];
int c[300010];
int ini[300010];
int fin[300010];
vector<int> G[300010];

void dfs(int u, int p = -1) {
    ini[u] = pos;
    if(b[u] != c[u]) {
        s.update(pos, 1);
        if(b[u]) bl.update(pos, 1), black.insert(pos);
        else wt.update(pos, 1), white.insert(pos);
    }
    pos++;
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    fin[u] = pos;
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    
    s.build(1000000);
    wt.build(1000000);
    bl.build(1000000);
    vector<pair<int,int> > st;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        st.emplace_back(a[i],i);
    }

    sort(st.begin(), st.end());

    for (int i = 0; i < n - 1; i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1);

    if(bl.query(ini[1], fin[1]) != wt.query(ini[1], fin[1])) return cout << "-1\n", 0;

    long long ans = 0;
    
    for (auto p: st) {
        long long cost = p.first;
        int id = p.second;
        int pini = ini[id];
        int pfin = fin[id] - 1;
        pfin = max(pfin, 0);
        if(!s.query(pini, pfin)) continue;
        int mn = min(max(0,bl.query(pini, pfin)), max(0,wt.query(pini, pfin)));
        ans += 2LL * mn * cost;
        while(mn--) {
            auto x = *black.lower_bound(pini);
            if(x >= 0 and x <= pos) {
                black.erase(x);
                bl.update(x, 0);
                s.update(x, 0);
            }

            auto y = *white.lower_bound(pini);
            if(y >= 0 and y <= pos) {
                white.erase(y);
                wt.update(y, 0);
                s.update(y, 0);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

