#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[500010];
int a[500010];
void init() { for (int i = 0; i < 500010; ++i) p[i] = i;}
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]);}
void merge(int x, int y) { p[find(y)] = find(x);}

int main() {
    
    init();
    cin >> n >> m;
    
    vector<pair<int, pair<int,int> > > e(m),de;

    for (auto &x: e) 
        cin >> x.second.first >> x.second.second >> x.first;

    de = e;
    sort(e.begin(), e.end());
    
    for (auto x: e) {
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if(find(u) != find(v)) {
            merge(u,v);
            a[w]++;
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int k;
        cin >> k;
        
        map<int,int> mp;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            x--;
            mp[de[x].first]++;
        }
        
        bool flag = 1;
        for (auto p: mp) {
            flag &= a[p.first] == p.second;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
   
    
    return 0;
}

