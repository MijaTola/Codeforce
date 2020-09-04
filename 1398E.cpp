#include <bits/stdc++.h>

using namespace std;


struct SegmentTree {

    int n;
    vector<long long> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(3 * _, 0);
        n = _;
    }

    long long op(long long a, long long b) {
        return a + b;
    }
    void update(int pos,int value){
        for (st[pos += n] += value; pos > 1; pos>>=1)
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
    
    int n;
    cin >> n;
    long long ans = 0;

    SegmentTree st1,st2;
    multiset<int> nor, dou;
    while(n--) {
        st1.build(100010);
        st2.build(100010);
        int x,y;
        cin >> x >> y;
        if(x == 0) {
            if(y > 0) {
                ans += y;
                nor.insert(y);
                st1.update(y, 1);
                st2.update(y, y);
                
            } else {
                ans -= y;
                nor.erase(nor.lower_bound(y));
                st1.update(y, -1);
                st2.update(y, -y);
            }
        } else {
            if(y > 0) {
                ans += y;
                dou.insert(y);
                st1.update(y, 1);
                st2.update(y, y);
            } else {
                ans -= y;
                dou.erase(nor.lower_bound(y));
                st1.update(y, -1);
                st2.update(y, -y);
            }
        }

        
        int a = 0, b = 100001;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(st1.query(mid, 100000) >= (int)dou.size()) a = mid;
            else b = mid;
        }
    
        
        long long current = st2.query(a, 100000);
        int total = st1.query(a, 100000);
        total -= dou.size() - 1;
        current -= a * total;
        cout << ans + current << "\n";

        
    }

    return 0;
}

