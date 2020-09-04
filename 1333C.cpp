#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
long long b[200010];
map<long long, vector<int> > mp;

int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        b[i] = v[i];
    }
    
    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
    }

    for (int i = 0; i < n; ++i)
        mp[b[i]].push_back(i);
    
    long long cur = 0, ans = 0;
    vector<pair<int,int> > no;

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(mp[cur].begin(), mp[cur].end(), i) - mp[cur].begin();
        if(!mp.count(cur)) {
            cur += v[i];
            continue;
        }
        if(pos == (int)mp[cur].size()) {
            cur += v[i];
            continue;
        }
        if(!no.empty() and no.back().second > mp[cur][pos]) {
            no.pop_back();
        }
        no.push_back({i, mp[cur][pos]});
        cur += v[i];
    }

    set<int> lim;
    set<pair<int,int> > ini;
    for (auto p: no) {
        lim.insert(p.second);
        ini.insert({p.first,p.second});
    }
    lim.insert(n);
    for (int i = 0; i < n; ++i) {
        while(i > (*ini.begin()).first and ini.size()) {
            lim.erase((*ini.begin()).second);
            ini.erase(ini.begin());
        }
        int pos = *lim.lower_bound(i);
        ans += pos - i;
    }
   
    cout << ans << "\n";
    return 0;
}

