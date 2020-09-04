#include <bits/stdc++.h>

using namespace std;

vector<int> G[123];
int visited[123];
int ans;
int mini;
void dfs(int u){
	ans++;
	//cout << u << " ";
	visited[u] = true;
	mini = min(mini,(int)G[u].size());
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if(!visited[v])	dfs(v);
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	int count  = 0;
	int rest = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans = 0;
		mini = 2;
	//	cout << i << ": ";
		if(visited[i]) continue;
		visited[i] = true;
		dfs(i);
		if(mini == 2 and ans & 1) count++;
		else if(ans & 1) rest++;
	}
	if(rest & 1) count++;
	cout <<count << endl;
	return 0;
}