#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {

    int n;
    vector<long long> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(4 * _);
        n = _;
    }

    long long op(long long a, long long b) {
        return a + b;
    }
    void update(int pos, long long value){
        for (st[pos += n] = value; pos > 1; pos>>=1)
            st[pos>>1] = op(st[pos], st[pos ^ 1]);
    }
    // interval[l,r)
    long long query(int l,int r){
        long long ans = 0;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans = op(ans, st[l++]);
            if(r & 1) ans = op(ans, st[--r]);
        }
        return ans;
    }
};

int main() {
    
    SegmentTree st,st2;
    st.build(1000010);
    st2.build(1000010);

    int n;
    cin >> n;
    vector<pair<long long,int> > v;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back({x, i});
        st.update(i, x);
        st2.update(i, 1);
    }

    sort(v.begin(), v.end());

    long double ans = 0;
    int pos = 0;

    for (int i = 0; i < n; ++i) {
        while(abs(v[pos].first - v[i].first) <= 1 and pos < n) {
            int p = v[pos].second;
            st.update(p, 0);
            st2.update(p, 0);
            pos++;
        }
        int p = v[i].second;

        long long b = st2.query(0, p);
        long long a = st.query(0, p);
        long long x = st2.query(p, n);
        long long y = st.query(p, n);

        ans += b * v[i].first - a;
        ans += y - x * v[i].first;

    }
    cout.precision(0);
    cout << fixed << ans << "\n";
    return 0;
}

