#include <bits/stdc++.h>

using namespace std;

vector<int> G[100010];

long double f(int u, int p) {
    long double cur = 0;
    for (int v: G[u]) {
        if(v == p) continue;
        cur += f(v, u) + 1;
    }
    return cur ? cur / (G[u].size() - (p != 0)) : 0;
}

int main(){
    int n; 
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    printf("%.15Lf\n", f(1, 0));
    return 0;
}

