#include <bits/stdc++.h>

using namespace std;

int n;

int v[200010];
vector<int> q[200010];
vector<int> b;
bool vis[200010];
int pos[200010];
int c[200010];
int main(){
    
    memset(vis,false,sizeof vis);
    memset(pos,0,sizeof pos);
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    for (int i = 0; i < n; ++i){
        q[v[i]].push_back(i);
        c[v[i]]++;
    }

    for (int i = 1; i < 200010; ++i)
        if(q[i].size() == 0) b.push_back(i);

    
    int p  = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int cur = v[i];
        if(q[cur].size() > 1){
            int u = q[cur][pos[cur]];
            if(cur > b[p]){
                if(c[cur] == 1 and !vis[cur]) continue;
                ans++;
                v[i] = b[p++];
            }else{
                if(!vis[cur]){
                    vis[cur] = 1;
                }else{
                    if(c[cur] == 1 and !vis[cur]) continue;
                    v[i] = b[p++];
                    ans++;
                }
            }
            c[cur]--;
            pos[cur]++;
        }
    }
    
    printf("%d\n",ans);
    for (int i = 0; i < n; ++i)
        printf("%d ", v[i]);
    puts("");
    return 0;
}

