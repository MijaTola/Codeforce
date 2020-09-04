#include <bits/stdc++.h>

using namespace std;

int a[500010];

struct segmentTree {
    vector<int> st;
    int n;
    segmentTree(int _) {
        n = _;
        st.resize(3 * n);   
    }
    void build(int node, int l, int r){
        if(l == r){ st[node] = a[l]; return;}
        int mid = (l + r) / 2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        st[node] = __gcd(st[2 * node], st[2 * node + 1]);
    }

    int query(int node, int l, int r, int i, int j){
        if(i > r or j < l) return 0;
        if(i <= l and r <= j) return st[node];
        int mid = (r + l) / 2;
        int p1 = query(2*node,l,mid,i,j);
        int p2 = query(2*node+1,mid+1,r,i,j);
        return __gcd(p1, p2);
    }

    int query(int i,int j){ return query(1,0,n-1,i,j);}

    void update(int node, int l, int r, int i, int x) {
        if(l == r) {
            st[node] = x;
            return;
        }
        int mid = (r + l) / 2;
        if(i <= mid) update(2 * node, l, mid, i, x);
        else update(2 * node + 1, mid + 1, r, i , x);
        st[node] = __gcd(st[2 * node], st[2 * node + 1]);
    }

    int f(int l, int r, int x){
        if(l == r) return 1;
        int mid = (l + r) / 2;
        int a = query(l, mid) % x != 0;
        int b = query(mid + 1, r) % x != 0;
        if(a and b) return 0;
        int ans = 1;
        if(a) ans &= f(l, mid, x);
        if(b) ans &= f(mid + 1, r, x);
        return ans;
    }
};

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    segmentTree st(n);
    st.build(1, 0, n - 1);

    int q;
    scanf("%d", &q);

    while(q--) {
        int t,l,r,x;
        scanf("%d %d %d", &t, &l, &r);

        if(t == 1) {
            scanf("%d", &x);
            l--,r--;
            if(st.query(l, r) % x == 0)
                puts("YES");
            else if(st.f(l, r, x)) puts("YES");
            else puts("NO");
        } else {
            st.update(1, 0, n - 1, l - 1, r);
        }
    }

    return 0;
}

