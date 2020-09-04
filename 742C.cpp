#include <iostream>
#include <vector>
#include <stack>
#include <cstring> 
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> G[110];
vector<int> GC[110];
int scc[110];
bool vis[110];
int state[110];
stack<int> s;
int n;
int cmp[110];
void dfs(int u){
	for (int x: G[u]){
		if(!vis[x]){
			vis[x] = true;
			dfs(x);
		}
	}
	s.push(u);
}
void dfs2(int u,int num){
	for (int x: GC[u]){
		if(scc[x] == -1){
			scc[x] = num;
			dfs2(x,num);
		}
	}
}
int kosaraju(){
	for (int i = 1; i <= n; ++i){
		if(!vis[i]){
			vis[i] = true;
			dfs(i);
		} 
	}
	int color = 0;
	while(!s.empty()){
		int u = s.top(); s.pop();
		if(scc[u] == -1){
			scc[u] = ++color;
			dfs2(u,color);
		}
	}
	return color;
}

bool cycle(int u){
    bool flag = false;
    for (int v: G[u]){
        if(state[v] == 1) return true;
        if(scc[v] == scc[u]  and state[v] == 0){
            state[v] = 1;
            flag |= cycle(v);
            state[v] = 2;
        }
    }
    return flag;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
    memset(vis,false,sizeof vis);
    memset(scc,-1,sizeof scc);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		int x; cin >> x;
		G[i].push_back(x);
        GC[x].push_back(i);
	}

	int c = kosaraju();
    memset(vis,false,sizeof vis);
	for (int i = 1; i <= n; ++i){
        cmp[scc[i]]++;
        if(!vis[scc[i]]) if(!cycle(i)) return cout << -1 << "\n",0;
        vis[scc[i]] = true;
    }
        
    int ans = (cmp[1]%2==0?cmp[1]/2:cmp[1]);
    for (int i = 2; i <= c; ++i){
        if(cmp[i]%2 == 0) cmp[i]/=2;
        ans = ans/__gcd(ans,cmp[i])*cmp[i];
    }
    cout << ans << "\n";
    return 0;
}
	
