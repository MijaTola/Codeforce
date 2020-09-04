#include <bits/stdc++.h>

using namespace std;

int v[200010];
int l[200010];
int r[200010];
int p[200010];

struct SegmentTree {

    int n;
    vector<int> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(3 * _);
        n = _;
    }

    int op(int a, int b) {
        return max(a,b);
    }
    void update(int pos,int value){
        for (st[pos += n]= value; pos > 1; pos>>=1)
            st[pos>>1] = op(st[pos], st[pos ^ 1]);
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = -1e9;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans = op(ans, st[l++]);
            if(r & 1) ans = op(ans, st[--r]);
        }
        return ans;
    }
};

int main() {

    int n;
    scanf("%d", &n);
    
    SegmentTree st;
    st.build(200010);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        st.update(i, v[i]);
        p[v[i]] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        int a = -1, b = i;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(st.query(mid, i) <= v[i]) b = mid;
            else a = mid;
        }
        l[i] = b;

        a = i, b = n;
        
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(st.query(i, mid) <= v[i]) a = mid;
            else b = mid;
        }
        r[i] = a;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int dl = i - l[i], dr = r[i] - i;
        if(dl <= dr) {
            for (int j = i - 1; j >= l[i]; j--) {
                int x = v[j];
                int y = v[i] - x;
                if(y < 0) continue;
                ans += p[y] > i and p[y] <= r[i];
            }
        } else {
            for (int j = i + 1; j <= r[i]; ++j) {
                int x = v[j];
                int y = v[i] - x;
                if(y < 0) continue;
                ans += p[y] < i and p[y] >= l[i];
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}

