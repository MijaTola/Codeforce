#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {

    int n;
    vector<int> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(3 * _);
        n = _;
    }

    int op(int a, int b) {
        return a + b;
    }
    void update(int pos,int value){
        for (st[pos += n]= value; pos > 1; pos>>=1)
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

int cnt[100010];
int main() {
    
    int n;
    cin >> n;

    vector<int> v(n);
    SegmentTree st;
    st.build(2000100);

    set<int> s;

    for (int i = 0; i <= 2000100; ++i)
        s.insert(i);

    for (int &x: v) {
        cin >> x;
        cnt[x]++;
        s.erase(x);
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if(st.query(0, v[i] - 1) >= v[i] - 1) {
            int x = *s.begin();
            st.update(x, 1);
            s.erase(x);
            ans.push_back(x);
            cnt[v[i]]--;
            if(!cnt[v[i]]) s.insert(v[i]);
        } else return cout << "-1\n", 0;
    }

    for (int x: ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}

