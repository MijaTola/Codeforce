#include <bits/stdc++.h>

using namespace std;

int n,x,y;
int in[1010];
set<int> G[1010];
int main() {


    auto ask = [] (int x, int y) {
        printf("? %d %d\n", x, y);
        fflush(stdout);
        int z;
        scanf("%d", &z);
        return z;
    };

    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        in[x]++, in[y]++;
        G[x].insert(y);
        G[y].insert(x);
    }

    vector<int> leaf;
    for (int i = 1; i <= n; ++i) 
        if(in[i] == 1) leaf.push_back(i);

    while((int)leaf.size() > 1) {
        int u = leaf.back();
        leaf.pop_back();
        int v = leaf.back();
        leaf.pop_back();
        int p = ask(u, v);
        if(p == u or p == v) {
            printf("! %d\n", p);
            fflush(stdout);
            return 0;
        } else {
            int nu = *G[u].begin();
            G[nu].erase(u);
            in[nu]--;
            if(in[nu] == 1) leaf.push_back(nu);
            int nv = *G[v].begin();
            G[nv].erase(v);
            in[nv]--;
            if(in[nv] == 1) leaf.push_back(nv);
        }
    }
    
    assert(leaf.size() == 1);
    printf("! %d\n", leaf[0]);
    fflush(stdout);
        

    
    return 0;
}

