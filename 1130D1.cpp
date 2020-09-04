#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
vector<pair<int,int> > G[5010];
int p[5010];
int fin[5010];

int f(int id) {
    memset(p, 0, sizeof p);
    memset(fin, 0, sizeof fin);
    int dm = m;
    int pos = id;
    int cnt = 0;
    while(dm > 0) {
        if(p[pos] >= (int)G[pos].size()) {
            dm -= fin[pos];
            fin[pos] = 0;
            cnt++;
            pos++;
            pos %= n;
            continue;
        }
        int candie = G[pos][p[pos]++].second;
        fin[candie]++;
        dm -= fin[pos];
        fin[pos] = 0;
        pos++;
        cnt++;
        pos %= n;
    }
    return cnt - 1;
}
int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        x--,y--;
        int dis = y - x;
        if(y < x) dis = (y + n) - x;
        G[x].push_back({dis,y});
    }
    
    for (int i = 0; i < n; ++i) 
        sort(G[i].rbegin(), G[i].rend());
    
    
    for (int i = 0; i < n; ++i) 
        cout << f(i) << " ";
    cout << "\n";
    
    return 0;
}

