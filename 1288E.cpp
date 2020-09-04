#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {

    int n;
    vector<int> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(3 * _, 0);
        n = _;
    }

    int op(int a, int b) {
        return a + b;
    }

    void update(int pos,int value){
        for (st[pos += n] += value; pos > 1; pos>>=1)
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

int last[300010];
bool vis[300010];
int mx[300010];
int v[300010];

int main() {

    memset(last, -1, sizeof last);

    int n,m;
    cin >> n >> m;
    
    SegmentTree st;
    st.build(m + 10);

    last[1] = 0;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        v[i] = x;
        mx[i] = i;
        if(last[x] == -1) {
            st.update(i, 1);
        } else {
            mx[x] = max(mx[x], 1 + st.query(last[x] + 1, i - 1));
            st.update(last[x], -1);
            st.update(i, 1);
        }

        last[x] = i;
    }
    
    SegmentTree st2;
    st2.build(n + 10);
    
    for (int i = 1; i <= m; ++i) {
        if(vis[v[i]]) continue;
        vis[v[i]] = 1;
        mx[v[i]] = max(mx[v[i]], v[i] + st2.query(v[i] + 1, n));
        st2.update(v[i], 1);
    }

    for (int i = 1; i <= n; ++i) {
        if(last[i] == -1) {
            mx[i] = max(mx[i], i + st2.query(i + 1, n));
        }
    }

    for (int i = 1; i <= n; ++i) {
        if(last[i] != -1)
            mx[i] = max(mx[i], 1 + st.query(last[i] + 1, m));
        if(last[i] == -1) {
            cout << i << " " << mx[i] << "\n";
        } else {
            cout << 1 << " " << mx[i] << "\n";
        }
    }
    return 0;
}

