#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
ordered_set;


struct ST {
    int stH[800010];
    int n;
    ST(int _) {n = _;}
    void updateH(int pos,int value){
        for (stH[pos+=n]= value; pos > 1; pos>>=1)
            stH[pos>>1] = max(stH[pos], stH[pos^1]); 
    }

    // interval[l,r)
    int queryH(int l,int r){
        int ans = 0;
        r++;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ans = max(ans, stH[l++]);
            if(r&1) ans = max(ans, stH[--r]);
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int w,h,n;
    ordered_set H,W;

    cin >> w >> h >> n;
    H.insert(h);
    ST sh(h + 1);
    sh.updateH(h, h);
    W.insert(w);
    ST sw(w + 1);
    sw.updateH(w, w);
    long long hmx = h, wmx = w;
    while(n--) {
        char c;
        int x;
        cin >> c >> x;

        if(c == 'H') {
            int right = H.order_of_key(x);
            int left = 0;
            if(right) left = *H.find_by_order(right - 1);
            right = *H.find_by_order(right);
            H.insert(x);
            sh.updateH(right, 0);
            sh.updateH(x, x - left);
            sh.updateH(right, right - x);
            hmx = sh.queryH(1, h + 1);
        } else {
            int right = W.order_of_key(x);
            int left = 0;
            if(right) left = *W.find_by_order(right - 1);
            right = *W.find_by_order(right);

            W.insert(x);
            sw.updateH(right, 0);
            sw.updateH(x, x - left);
            sw.updateH(right, right - x);
            wmx = sw.queryH(1, w + 1);
        }
        cout << hmx * wmx << "\n";

    }

    return 0;
}

