#include <bits/stdc++.h>

using namespace std;

int b[110];
int a[1010];
int vis[1010];

int main() {
    int t;
    cin >> t;

    while(t--) {
        memset(vis, 0, sizeof vis);
        int n;
        cin >> n;
        
        vector<pair<int,int> > u;
        set<int> no;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            u.emplace_back(b[i], i);
            vis[b[i]] = 1;
        }
        
        for (int i = 1; i <= 2 * n; ++i)
            if(!vis[i]) no.insert(i);
        
        
        bool flag = 1;
        for (int i = 0; i < (int)u.size(); ++i) {
            auto it = no.lower_bound(u[i].first);
            if(it != no.end()) {
                no.erase(it);
                a[2 * u[i].second + 1] = *it;
            } else flag = 0;
        }
        
        if(!flag) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; ++i) 
            a[2 * i] = b[i];

        for (int i = 0; i < 2 * n; ++i) 
            cout << a[i] << " ";
        cout << "\n";

    }
    return 0;
}

