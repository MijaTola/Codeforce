#include <bits/stdc++.h>

using namespace std;

int a[150010];
int st[2 * 150010];
int build(int node, int l, int r) {
    if(l == r) return st[node] = a[l],1;
    int mid = (l + r) / 2;
    bool c = build(2 * node, l, mid);
    build(2 * node + 1, mid  + 1, r);
    int t1 = st[2 * node];
    int t2 = st[2 * node + 1];
    int ans = 0;
    if(c) ans = t1 | t2;
    else ans = t1 ^ t2;
    st[node] = ans;
    return !c;
}

bool update(int node, int l, int r, int pos, int val) {
    if(l == r and l == pos) {
        return st[node] = a[pos] = val, 1;
    }
    if(l == r) return 1;
    int mid = (l + r) / 2;
    bool f = 0;
    if(l <= pos and pos <= mid) f = update(2 * node, l, mid, pos, val);
    else f = update(2 * node + 1, mid + 1, r, pos, val);
    int ans = 0;
    if(f) ans = st[2 * node] | st[2 * node + 1];
    else ans = st[2 * node] ^ st[2 * node + 1];
    st[node] = ans;
    return !f;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < pow(2,n); ++i)
        cin >> a[i];
    build(1,0,pow(2, n) - 1);
    while(m--) {
        int p,x; cin >> p >> x;
        p--;
        update(1,0, pow(2,n) - 1, p, x);
        cout << st[1] << "\n";
    }
    return 0;
}
