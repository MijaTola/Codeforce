#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
int v[200010];
vector<pair<int,int> > e;

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        e.emplace_back(x, v[i]);
    }

    sort(e.begin(), e.end());

    int lim = 1e9;

    for (int i = 0; i < n; ++i) {

    }
    return 0;
}

