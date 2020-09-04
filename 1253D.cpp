#include <bits/stdc++.h>
 
using namespace std;
 
set<int> s[200010];
 
int n,m,x,y;
int p[200010];
int mx[200010];
int mn[200010];
long long sum[200010];
 
void init() {
    for (int i = 0; i < 200010; ++i) {
        p[i] = i;
        mn[i] = 1e9;
    }
}
 
int find (int x) {
    return x == p[x] ? p[x] : p[x] = find(p[x]);
}
 
void merge(int x, int y) {
    p[find(y)] = find(x);
}
 
long long get(int x) {
    return x * (x + 1) / 2;
}
 
int main() {
    init();
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        if(find(x) != find(y))
            merge(x,y);
    }
    set<int> parents;
    for (int i = 1; i <= n; ++i) {
        parents.insert(find(i));
        mx[find(i)] = max(mx[find(i)], i);
        mn[find(i)] = min(mn[find(i)], i);
    }
    
    vector<pair<pair<int,int>, int> > r;
 
    for (auto a: parents) 
        r.push_back({{mn[a], mx[a]}, a});
 
    sort(r.begin(), r.end());
    priority_queue<pair<int,int> > q;
    int ans = 0;
    for (int i = 0; i < (int) r.size(); ++i) {
        
        while(!q.empty() and q.top().first < r[i].first.first) q.pop();
 
        if(!q.empty()) ans++;
        q.push({r[i].first.second, r[i].second});
    }
    
    cout << ans << "\n";
    
  
    return 0;
}

