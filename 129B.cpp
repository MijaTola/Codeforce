#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n,m;
int dfs_num[1000];
vi graph[1000];

/*void dfs(int u){
	dfs_num[u] = 0;
	for (int i = 0; i < graph[u].size(); ++i)
	{
		int node = graph[u][i];
		if(dfs_num[node] == -1) dfs(node);
	}
}*/
int main(){
	cin >> n >> m;
	int x,y;
	memset(dfs_num,-1,sizeof dfs_num);
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int ans = 0;
	bool sw = false;
	do{
		vi h;
		sw = false;
		for (int i = 1; i <= n; ++i)
		{
			if(dfs_num[i] == -1){
				int c = 0;
				for (int j = 0; j < graph[i].size(); ++j){
					int pos = graph[i][j];
					if(dfs_num[pos] == -1) c++;	
				}
				if(c == 1) {h.push_back(i); sw = true;		}
			}
		}
		for (int i = 0; i < h.size(); ++i)
			dfs_num[h[i]] = 0;
		ans++;
	}while(sw);
	cout << ans-1;
	return 0;
}