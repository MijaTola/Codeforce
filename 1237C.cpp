#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>, int> > v, edges;

long long dis(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
    return abs(a.first.first - b.first.first) + abs(a.first.second - b.first.second) + abs(a.second - b.second);
}

bool vis[2010];
int main() {
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        v.push_back({{x,y}, z});
    }
    
    for (int i = 0 ; i < n; ++i) {
        for (int j = 0;j < n; ++j) {
            if(i == j) continue;
            edges.push_back({{dis(v[i], v[j]),i},j});
        }
    }

    sort(edges.begin(), edges.end());
    
    for (auto e: edges) {
        int x = e.first.second;
        int y = e.second;
        if(vis[x] or vis[y]) continue;
        vis[x] = vis[y] = 1;
        cout << x + 1 << " " << y + 1 << "\n";
             
    }
    return 0;
}

