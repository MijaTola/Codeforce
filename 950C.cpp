#include <bits/stdc++.h>

using namespace std;

int sz[200010];
vector<int> v[200010];

int main(){

    string s; cin >> s;

    //if(s[0] == '1') return cout << "-1\n",0;

    int mx = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '0') {
            int cur = 0;
            while(v[cur].size() % 2 != 0 and cur < (int)s.size()) cur++;
            if(cur < (int)s.size()) {
                v[cur].push_back(i);
                mx = max(cur,mx);
            }
        }else {
            int cur = 0;
            while(v[cur].size() % 2 == 0 and cur < (int)s.size()) cur++;

            if(cur < (int)s.size()) {
                v[cur].push_back(i);
                mx = max(cur,mx);
            }
        }
    }
    mx++;
    bool f = 0;
    for (int i = 0; i < mx; ++i) {
        if(v[i].size() == 0) continue;
        f = 1;
        if(v[i].size() % 2 == 0) return cout <<"-1\n",0;
    }
    if(!f) return cout << "-1\n",0;
    cout << mx << "\n";
    for (int i = 0; i < mx; ++i) {
        if(v[i].size() == 0) continue;
        cout << v[i].size() << " ";
        assert(v[i].size() % 2 != 0);
        for(int j: v[i]) cout << j + 1 << " ";
        cout << "\n";
    }
    return 0;
}

