#include <bits/stdc++.h>

using namespace std;

int n;
long long x,y;
long long b[2000010];
vector<long long> path;
vector<pair<long long, long long> > v;
int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        v.emplace_back(x,y);
        path.push_back(x);
        path.push_back(y + 1);
    }
   
    sort(path.begin(), path.end());

    for (auto p: v) {
        b[lower_bound(path.begin(), path.end(), p.first) - path.begin()]++;
        b[lower_bound(path.begin(), path.end(), p.second + 1) - path.begin()]--;
    }
    
    map<long long, long long> ans;
    
    for (int i = 1; i < (int)path.size(); ++i)
        b[i] += b[i - 1];


    for (int i = 1; i < (int)path.size(); ++i)
        ans[b[i - 1]] += path[i] - path[i - 1];

    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
    puts("");
    return 0;
}

