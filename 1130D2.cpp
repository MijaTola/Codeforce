#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
int G[5010],c[5010];

pair<int,int> find(int ini) {
    int mx = 0;
    int id = 0;
    for (int i = 0; i < n; ++i) {
        if(c[(i + ini) % n] >= mx) {
            mx = c[(i + ini) % n];
            id = (i + ini) % n;
        }
    }
    return {mx, id};
}
int main() {

    for (int i = 0; i < 5010; ++i) G[i] = 1e9;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        x--,y--;
        int dis = y - x;
        if(y < x) dis = (y + n) - x;
        G[x] = min(dis,G[x]);
        c[x]++;
    }
    

    int dn = n;
    if(n == 1) dn = 2;

    for (int i = 0; i < n; ++i) {
        pair<int,int> pr = find(i);
        int id = pr.second;
        int mx = pr.first;
        int dis = id - i;
        if(id < i) dis = (id + n) - i;
        long long ans = (mx - 1) * dn + dis + G[id];
        cout << ans << " " << id << " " << i << " " << dis << "\n";;
    }
    cout << "\n";
    return 0;
}


