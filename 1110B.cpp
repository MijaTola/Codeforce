#include <bits/stdc++.h>

using namespace std;

int n,m,k;

int v[100010];
int vis[100010];

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; ++i) 
        scanf("%d", v + i);
    
    priority_queue<pair<int,int> > q;
    int cur = n;
    long long ans = n;

    for (int i = 0; i < n - 1; ++i) 
        q.push({-(v[i + 1] - v[i]), i});
    
    while(cur > k) {
        ans--;
        ans += -q.top().first;
        int i = q.top().second;
        q.pop();
        cur--;
        vis[i] = vis[i + 1] = 1;
    }

    cout << ans << "\n";
    return 0;
}

