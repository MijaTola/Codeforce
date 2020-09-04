#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set mp[11][11][30];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;

    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j < (int)s.size(); ++j) {
            mp[i][j % i][s[j] - 'A'].insert(j);
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int p;
            char x;
            cin >> p >> x;
            p--;
            for (int i = 1; i <= 10; ++i) {
                mp[i][p % i][s[p] - 'A'].erase(mp[i][p % i][s[p] - 'A'].lower_bound(p));
                mp[i][p % i][x - 'A'].insert(p);
            }
            s[p] = x;

        } else {
            int l,r;
            string x;

            cin >> l >> r >> x;
            l--,r--;
            int ans = 0;

            for (int i = 0, ini = l % x.size(); i < (int)x.size(); i++, ini++) {
                char cur = x[i];
                int dl = mp[x.size()][ini % x.size()][cur - 'A'].order_of_key(l);
                int dr = mp[x.size()][ini % x.size()][cur - 'A'].order_of_key(r + 1);
                ans += dr - dl;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

