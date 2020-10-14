#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
int n,q;
ordered_set BIT[200010];
int a[200010];
int da[200010];
int b[200010];
int db[200010];

void insert(int x, int y) {
    for(; x <= n; x += x&-x)
        BIT[x].insert(y);
}

void erase(int x, int y) {
    for (; x <= n; x += x&-x)
        BIT[x].erase(y);
}

int query(int x, int l, int r) {
    int ans = 0;
    for (; x > 0; x -= x&-x) {
        int dr = BIT[x].order_of_key(r + 1);
        int dl = BIT[x].order_of_key(l);
        ans += dr - dl;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        da[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        insert(da[b[i]], i);
    }
    
    while(q--) {
        int kind;
        cin >> kind;

        if(kind == 1) {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            cout << query(b, c, d) - query(a - 1, c, d) << "\n";
        } else {
            int x,y;
            cin >> x >> y;
            erase(da[b[x]], x);
            erase(da[b[y]], y);
            swap(b[x], b[y]);
            insert(da[b[x]], x);
            insert(da[b[y]], y);
        }
    }


    return 0;
}

