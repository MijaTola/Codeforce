#include <bits/stdc++.h>

using namespace std;

int n,m,k;

int c[210][210];

int main() {
    
    cin >> n >> m >> k;
    
    vector<pair<int,int> > ini(k);
    
    int d = 0;
    int l = 0;

    for (int i = 0; i < k; ++i) {
        cin >> ini[i].first >> ini[i].second;
        ini[i].first--;
        ini[i].second--;
        d = max(d, ini[i].first);
        l = max(l, ini[i].second);
    }
    
    for (int i = 0; i < k; ++i) {
        int x,y;
        cin >> x >> y;
        c[x][y] = 1;
    }

    string ans = "";

    for (int i = 0; i < l; ++i)
        ans += 'L';

    for (int i = 0; i < d; ++i)
        ans += 'U';

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if(i % 2 == 0) ans += 'R';
            else ans += 'L';
        }
        if(i + 1 < n) ans += 'D';
    }

    if((int)ans.size() > 2 * n * m) cout << "-1\n";
    else cout << ans.size() << "\n" << ans << "\n";
    
    
    return 0;
}

