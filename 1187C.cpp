#include <bits/stdc++.h>

using namespace std;

int ans[1010];
bool vis[1010];

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first)
        return abs(a.first - a.second) > abs(b.first - b.second);
    return a.first < b.first;
}
int main() {
    memset(ans, -1, sizeof ans);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > no,v;
    while(m--) {
        int t,l,r;
        cin >> t >> l >> r;
        if(t) v.push_back({l,r});
        else no.push_back({l,r});
    }
        
    sort(v.begin(), v.end(), cmp);

    int cur = 1e9;
    for (auto p: v) {
        int l = p.first;
        int r = p.second;
        set<int> s;
        for (int i = l; i <= r; ++i)
            if(ans[i] != -1) s.insert(ans[i]);
        if(s.size() == 1) {
            int val = *s.begin();   
            for (int i = l; i <= r; ++i)
                ans[i] = val;
        } else if(s.size() == 0) {
            for (int i = l; i <= r; ++i)
                ans[i] = cur;
            cur--;
        } 
    }
    sort(no.begin(), no.end(), cmp);
    for (auto p: no) {
        int l = p.first;
        int r = p.second;
        bool flag = 1;
        for (int i = l; i <= r; ++i) 
            flag &= ans[i] != -1;

        if(flag) {
            flag = 0;
            for (int i = l + 1; i <= r; ++i) {
                flag |= ans[i] < ans[i - 1];
            }
            if(!flag) return cout << "NO\n",0;
        } else {
            for (int i = l; i <= r; ++i)
                if(ans[i] == -1) ans[i] = cur--;
        }
    }
    for (int i = 1; i <= n; ++i)
        if(ans[i] == -1) ans[i] = 1;
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
