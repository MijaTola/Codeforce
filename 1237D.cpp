#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];

struct SegmentTree {
    int n;
    int type;
    vector<int> st;
    int NEUTRO;
    void init(int _, int __, int ___) {
        n =  _;
        st.resize(_);
        NEUTRO = ___;
        type = __;
    }
    SegmentTree() {}
    
    int ope(int x, int y) {
        if(type) return max(x,y);
        return min(x,y);
    }

    void update(int pos,int value){
        for (st[pos+=n]= value; pos > 1; pos>>=1) {
            st[pos>>1] = ope(st[pos],st[pos^1]);
        }
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = NEUTRO;
        r++;
        for (l += n,r +=n ; l < r ; l >>= 1,r >>= 1){
            if(l&1) ans = ope(ans,st[l++]);
            if(r&1) ans = ope(ans,st[--r]);
        }
        return ans;
    }
};

SegmentTree st;
int main() {
    cin >> n;
    
    st.init(2 * n, 0, 1e9);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[i] = v[i + n] = x;

        st.update(i, x);
        st.update(i + n, x);
    }
    
    auto ver = [] (int ini, int k) {
        int mn = v[ini + k];
        int mx = st.query(ini, k + ini - 1);
        cout << ini << " " << ini + k << ":\n";
        cout << mx << " " << mn << " test\n";
        cout << ((mx + 1) / 2 < mn) << " F\n";
        return (mx + 1) / 2 < mn;
    };

    
    //for (int i = 0; i < n; ++i) {
        int a = 0, b = n;
        int i = 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(i, mid)) a = mid;
            else b = mid;
        }
        cout << a + i<< " ";
    //}
    cout << "\n";


    return 0;
}

