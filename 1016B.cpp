#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main(){
    
    int n,m,q; cin >> n >> m >> q;
    string s,t; cin >> s >> t;
    for (int i = 0; i < n; ++i) {
        bool flag = 1;
        for (int j = 0; j < m; ++j) 
            flag &= (s[j + i] == t[j]);
        if(flag)v[i] = 1;
    }
    
    while(q--) {
        int x,y; cin >> x >> y;
        x--,y--;
        int ans = 0;
        for (int i = x; i <= y; ++i) 
            ans += (v[i] == 1 and i + m - 1 <= y);
        cout << ans << "\n";
    }
    return 0;
}

