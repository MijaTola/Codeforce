#include <bits/stdc++.h>

using namespace std;

vector<int> G[1000010];
int t[1000010];
int a[1000010];
int build(int u){
    a[u] = t[u];
    for (int i = 0; i < (int)G[u].size(); ++i){
        int v = G[u][i];
        a[u] += build(v);
    }
    return a[u];
}
int main(){
    int n;
    scanf("%d",&n);
    int root = -1;
    for (int i = 1; i <= n; ++i){
        int x,y; 
        scanf("%d %d",&x,t+i);
        if(x == 0) root = i;
        else G[x].push_back(i);
    }
    build(root);
    
    queue<pair<int,int> > q;
    
    q.push(make_pair(root,root));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cout << x << " " << y << "\n";
        if((x == 4 or x == 6) and (y == 4 or y == 6) and x != y){
            puts("found");
            cout << x << " " << y << "\n";
            cout << a[root] - a[x] - a[y] << " " << a[x] << " " << a[y] << "\n";
            break;
        }
        if(a[root] - a[x] - a[y] == a[x] and a[x] == a[y] and x != y)
            return printf("%d %d\n",x,y),0;
        for (int i = 0; i < (int)G[x].size(); ++i){
            int u = G[x][i];
            q.push(make_pair(u,y));
        }

        for (int i = 0; i < (int) G[x].size(); ++i){
            int u = G[x][i];
            q.push(make_pair(x,u));
        }
    }
    return 0;
}

