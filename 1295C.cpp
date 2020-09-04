#include <bits/stdc++.h>

using namespace std;

vector<int> v[30];
int main() {
    
    int c;
    cin >> c;

    while(c--) {

        for (int i = 0; i < 30; ++i) v[i].clear();
        string s,t;
        cin >> s >> t;
        
        int ini = -1, ans = 1;

        for (int i = 0; i < (int)s.size(); ++i) 
            v[s[i] - 'a'].push_back(i);
    
        bool flag = 1;
        for (int i = 0; i < (int)t.size(); ++i) {
            int cur = t[i] - 'a';
            int pos = upper_bound(v[cur].begin(), v[cur].end(), ini) - v[cur].begin();
            if(pos >= 0 and pos < (int)v[cur].size() and v[cur][pos] > ini) {
                ini = v[cur][pos];
            } else {
                ans++;
                ini = -1;
                pos = lower_bound(v[cur].begin(), v[cur].end(), ini) - v[cur].begin();
                if(pos >= 0 and pos < (int)v[cur].size()) 
                    ini = v[cur][pos];
                else {
                    flag = 0;
                    break;
                }
            }
        }
        
        if(flag)cout << ans << "\n";
        else cout << "-1\n";
        
    }
    return 0;
}

