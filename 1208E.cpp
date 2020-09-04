#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {

    int n;
    vector<int> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(2 * _ + 10);
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

SegmentTree st[1000010];
vector<int> v[1000010];
int ans[1000010];

int main() {

    int n,w;
    cin >> n >> w;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        st[i].build(k + 10);
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            st[i].update(j, x);
            v[i].push_back(x);
        }
    }

    for (int i = 0; i < n; ++i) {
        int sz = v[i].size();
        bool flag = 0;
        int l = 0, r = v[i].size();

        if(i + sz >= n) 
            l = (i + sz) + 1 - v[i].size();
        if(i - sz < 0) 
            r = v[i].size() - (i - sz) - 1;
        
        flag |= i + sz + 1 < n or i - sz - 1 < n;

        
    }

    
    for (int i = 0; i < w; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

