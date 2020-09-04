#include <bits/stdc++.h>

using namespace std;


map<string, string> mp;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string x,y;
        cin >> x >> y;
        mp[y] = x;
    }

    for (int i = 0; i < m; ++i) {
        string x,y;
        cin >> x >> y;
        string t = "";
        for (int j = 0; j < (int)y.size() - 1; ++j) t += y[j];
        string cur = mp[t];
        cout << x << " " << y << " #" << cur << "\n";
    }
    return 0;
}

