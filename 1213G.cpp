#include <bits/stdc++.h>

using namespace std;

int p[200010];
long long a[200010];
long long sz[200010];
vector<pair<long long, pair<long long, long long> > > e;
vector<pair<int,int> > q;
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

long long ans;
void merge(int x, int y) {
    ans += sz[find(x)] * sz[find(y)]; 
    sz[find(x)] += sz[find(y)];
    p[find(y)] = p[find(x)];
}

void init() {
    ans = 0;
    for (int i = 0; i < 200010; ++i)
        p[i] = i , sz[i] = 1;
}
int main() {
    
    int n,m;
    cin >> n >> m;
    init();
    for (int i = 0; i < n -1; i++) {
        int x,y,w;
        cin >> x >> y >> w;
        e.push_back({w, {x,y}});
    }

    sort(e.begin(), e.end());
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        q.push_back({x,i});
    }
    sort(q.begin(), q.end());
    int pos = 0;
    for (int i = 0; i < m; ++i) {
        while(pos < n - 1 and q[i].first >= e[pos].first ) {
            if(find(e[pos].second.first) != find(e[pos].second.second))
                merge(e[pos].second.first, e[pos].second.second);
            pos++;
        }
        a[q[i].second] = ans;
    }
    for (int i = 0; i < m; ++i)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}

