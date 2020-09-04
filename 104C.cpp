#include <bits/stdc++.h>

using namespace std;

#define pb push_back
vector<int> G[123];
bool visited[123];
int main(){
	int n,m;
	memset(visited,false,sizeof visited);
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int x,y; cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}

	queue<int> bfs;
	int edges = 0;
	bfs.push(1);
	while(!bfs.empty()){
		int u = bfs.front(); bfs.pop();
		for (int i = 0; i < G[u].size(); ++i)
		{
			if(!visited[G[u][i]]){
				cout <<u << ": "<< G[u][i] << " ";
				visited[G[u][i]] = true;
				bfs.push(G[u][i]);
				edges++;
			}
		}
		cout << endl;
	}
	cout << edges << " " << n << endl;
	if(n != m) cout << "NO";
	else if(edges == n) cout << "FHTAGN!";
	else  cout << "NO";
	return 0;
}