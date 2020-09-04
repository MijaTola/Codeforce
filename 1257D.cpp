#include <bits/stdc++.h>
 
using namespace std;
 
struct segmentTree {
 
    vector<int> st;
    int n;
    segmentTree(int _) {
        st.resize(3 * _);
        n = _;
    }
 
    void update(int pos,int value){
        for (st[pos+=n]= value; pos > 1; pos>>=1)
            st[pos>>1] = max(st[pos], st[pos^1]);
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = 0;
        r++;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ans = max(ans, st[l++]);
            if(r&1) ans = max(ans, st[--r]);
        }
        return ans;
    }
 
};
 
int t,n,m,x,y;
int b[200010];
 
int main() {
 
    scanf("%d",&t);
 
    while(t--) {
        vector<pair<int,int> > v;
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i) 
            scanf("%d", b + i);
        
 
        scanf("%d", &m);
        segmentTree st1(m), st2(n);
 
        
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &x,&y);
            v.emplace_back(y,x);
        }
    
        for (int i = 0; i < n; ++i)
            st2.update(i, b[i]);
 
        sort(v.begin(), v.end());
 
        for (int i = 0; i < m; ++i)
            st1.update(i, v[i].second);
 
     
        auto ver = [&v, &st1, &st2] (auto ini, auto dis) -> bool {
            auto p = lower_bound(v.begin(), v.end(), make_pair(dis, 0)) - v.begin();
            if(p == m) return 0;
            return st1.query(p,m) >= st2.query(ini, ini + dis - 1);
        };
 
        auto howfar = [&ver](int ini) {
            int a = 0, b = n + 1;
            while(b - a > 1) {
                int mid = (a + b) >> 1;
                if(ver(ini, mid)) a = mid;
                else b = mid;
            }
            return ini + a;
        };
            

        int ans = 0;
        int pos = 0;

        while(pos < n) {
            int next = howfar(pos);
            if(pos == next) break;
            pos = next;
            ans++;
        }
 
        printf("%d\n", pos >= n ? ans : -1);
    }
    return 0;
}
