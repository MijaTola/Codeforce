#include <bits/stdc++.h>

using namespace std;

int c[100][256];
int z[100][256];

vector<pair<string, string> > v;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string a,b;
        cin >> a >> b;
        v.push_back({a,b});
        for (char x: a)
            c[i][int(x)]++;
        
        for (char x: b)
            c[i][int(x)]++;
    }
    int pos = 0;
    int ans = -1, id = -1;
    while(k--) {
        int n,m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            string y;
            cin >> y;
            for (char x: y) 
                z[pos][int(x)]++;
        }
        int mx = 1e9;
        for (int i = 0; i < 256; ++i) {
            if(c[pos][i] == 0) continue;
            int cur = z[pos][i] / c[pos][i];
            mx = min(cur, mx);
        }
        
        if(mx > ans) {
            ans = mx;
            id = pos;
        }
        pos++;
    }

    cout << v[id].first << " " << v[id].second << "\n";
    return 0;
}

