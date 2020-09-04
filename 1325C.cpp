#include <bits/stdc++.h>

using namespace std;

int n,x,y;
vector<int> G[100010];
int in[100010];
vector<pair<int,int> > e,b;
map<pair<int,int>, int> mp;



int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
        e.emplace_back(x,y);
        in[x]++, in[y]++;
    }

    auto get = [] (int x, int y) {
        return make_pair(min(x,y), max(x,y) );
    };
    

    for (int i = 1; i <= n; ++i)
        b.emplace_back(in[i], i);

    sort(b.rbegin(), b.rend());
    
    int cnt = 0;
    for (auto p: b) {
        for (int v: G[p.second]) {
            if(!mp.count(get(v, p.second)))
                mp[get(v,p.second)] = cnt++;
        }
    }

    for (auto p: e) {
        cout << mp[get(p.first,p.second)] << "\n";
    }
    return 0;
}

