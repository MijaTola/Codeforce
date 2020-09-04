#include <bits/stdc++.h>

using namespace std;

int n,q;
int v[110];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> q;

    while(q--) {
        set<pair<int,int> > vis;
        cin >> n;
        
        for (int i = 1; i <= n; ++i) 
            cin >> v[i];

        for (int i = 1; i <= n; ++i) {
            int p = 1;
            while(v[p] != i) p++;
            p--;
            while(p >= 1 and !vis.count({p, p + 1}) and v[p] > v[p + 1]) {
                swap(v[p], v[p + 1]);
                vis.insert({p, p + 1});
                p--;
            }
        }
       

        for (int i = 1; i <= n; ++i)
            cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}

