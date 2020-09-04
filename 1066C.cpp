#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

using namespace std;

int val[200010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);   
    ordered_set  s;

    int q; cin >> q;
    int l = 0, r = 1;
    int sz = 0;
    while(q--) {
        char c; int x;
        cin >> c >> x;
        if(c == 'L') {
            val[x] = l;
            s.insert(l);
            l--;
            sz++;
        }
        if(c == 'R') {
            val[x] = r;
            s.insert(r);
            r++;
            sz++;
        }
        if(c == '?') {
            int f = val[x];
            int pos = s.order_of_key(f);
            cout << min(pos, sz - (pos + 1)) << "\n";
        }
    }

    return 0;
}
