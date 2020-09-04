#include <bits/stdc++.h>

using namespace std;

int n;
int p[2010];
long long k[2010];
long long c[2010];
long long mx[2010];
long long node[2010];

vector<pair<int,int> > v;
vector<pair<long long, pair<int,int> > > e;

void init() {
    for (int i = 0; i < 2010; ++i)
        p[i] = i;
}

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
    p[find(y)] = find(x);
}

long long cost(int i, int j) {
    long long dis = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
    return dis * (long long)((long long)k[i] + (long long)k[j]);
}

int main() {

    for (int i = 0; i < 2010; ++i) 
        mx[i] = LLONG_MAX;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    for (int i = 0; i < n; ++i)  {
        int x;
        cin >> x;
        e.push_back({x, {2005, i}});
    }


    for (int i = 0; i < n; ++i)
        cin >> k[i];
    
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) 
            e.push_back({cost(i,j), {i, j}});

    sort(e.begin(), e.end());

    long long ans = 0;
    vector<pair<long long, long long> > pans;

    init();
    set<int> s;
    for (int i = 0; i < (int) e.size(); ++i) {
        int x = e[i].second.first;
        int y = e[i].second.second;
        long long w = e[i].first;
        if(find(x) == find(y)) continue;
        merge(x, y);
        ans += w;
        if(x == 2005) s.insert(y + 1);
        else pans.push_back({x + 1, y + 1});
    }

    cout << ans << "\n";

    cout << s.size() << "\n";

    for (auto u: s) 
        cout << u << " ";
    cout << "\n";

    cout << pans.size() << "\n";
    for (auto u: pans)
        cout << u.first << " " << u.second << "\n";

    return 0;
}

