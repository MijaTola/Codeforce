#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {

    int t;
    cin >> t;
    
    map<char, pair<int,int> > mv;
    mv['L'] = {-1,0};
    mv['D'] = {0,-1};
    mv['U'] = {0, 1};
    mv['R'] = {1, 0};
    while(t--) {
        cin >> n >> s;

        int x = 0, y = 0;
        int mn = 1e9;
        int l = -1, r = -1;
        map<pair<int,int> , int> mp;
        mp[make_pair(0,0)] = -1;
        for (int i = 0; i < n; ++i) {
            x += mv[s[i]].first;
            y += mv[s[i]].second;
            if(mp.count({x,y})) {
                int pos = mp[make_pair(x,y)];
                if(i - pos + 1 < mn) {
                    mn = i - pos + 1;
                    l = pos + 1;
                    r = i;
                }
                mp[make_pair(x,y)] = i;
            } else mp[make_pair(x,y)] = i;
        }

        if(mn == 1e9) cout << "-1\n";
        else cout << l + 1 << " " << r + 1 << "\n";
    }
    return 0;
}


