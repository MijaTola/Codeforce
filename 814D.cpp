#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1);
int n;
long double ans = 0;
vector<tuple<int,int,int> > v;
vector<int> G[1010];

int depth[1010];

void dfs(int u, int d = 0) {
    depth[u] = d;
    long double val = get<0> (v[u]);
    if(d == 0 or d & 1) ans += val * val * pi;
    else ans -= val * val * pi;
    for (int dv: G[u])  dfs(dv, d + 1);
}

int main() {
    memset(depth, -1, sizeof depth);
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int x,y,r;
        cin >> x >> y >> r;
        v.emplace_back(r,x,y);
    }

    
    auto dis = [] (double a, double b, double x, double y) {
        return sqrt((a - x) * (a - x) + (b - y) * (b - y));
    };
    
    sort(v.rbegin(), v.rend());
    
    for (int i = 0; i < n; ++i) {
        int id = -1;
        double curR = 1e9;
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            double d = dis(get<1>(v[i]), get<2>(v[i]), get<1>(v[j]), get<2>(v[j]) );
            if(get<0> (v[j]) >= d and get<0>(v[j])> get<0> (v[i])) {
                if(get<0> (v[j]) < curR) {
                    curR = get<0> (v[j]);
                    id = j;
                }
            }
        }
        if (id != -1) G[id].push_back(i);
    }

    
    for (int i = 0; i < n; ++i) 
        if(depth[i] == -1) 
            dfs(i);

    cout.precision(10);
    cout << fixed << (double) ans << "\n";
    return 0;
}

