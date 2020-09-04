#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char maze[510][510];
bool visited[510][510];
int dist[510][510];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int wtf[510][510];
struct compare{
	bool operator ()(const pair<pair<int,int>, pair<int,bool> > a, const pair<pair<int,int>,pair<int,bool > > b){
		return a.second.first > b.second.first;
	}
};
int main(){
	for (int i = 0; i < 510; ++i)
		for (int j = 0; j < 510; ++j){
			visited[i][j] = false;
			dist[i][j] = 1e6;
		}
	int n,m;
	cin >> m >> n;
	int a,b; cin >> a >> b;
	priority_queue<pair<pair<int,int>,pair<int,bool> >, vector<pair<pair<int,int>,pair<int,bool> > >,compare > bfs;
	for (int i = 0;i <n;++i)
		for (int j = 0; j < m; ++j)
			cin >> maze[i][j];
	
	bfs.push(make_pair(make_pair(0,0),make_pair(0,true)));
	dist[0][0] = 0;
	wtf[0][0] = a;
	bool sw = false;
	while(!bfs.empty()){
		int x = bfs.top().first.first;
		int y = bfs.top().first.second;
		int d = bfs.top().second.first;
		bool type = bfs.top().second.second;
		bfs.pop();
		if(x == n-1 and y == m-1){
			sw = true;
			cout << d << endl;
			break;
		}
		if(visited[x][y]) continue;
		visited[x][y] = true;
		for (int i = 0; i < 4; ++i){
			int u = dx[i] + x;
			int v = dy[i] + y;
			if(u >= 0 and u < n and v >= 0 and v < m and maze[u][v] != '#'){
				if(type){
					if(dist[x][y] + b < dist[u][v]){
						wtf[u][v] = b;
						dist[u][v] = dist[x][y] + b;
						bfs.push(make_pair(make_pair(u,v),make_pair(dist[u][v],false)));
					}
				}else{
					if(dist[x][y] + a < dist[u][v]){
						wtf[u][v] = a;
						dist[u][v] = dist[x][y] + a;
							bfs.push(make_pair(make_pair(u,v),make_pair(dist[u][v],true)));
					}
				}
			}
		}
	}
	if(!sw) cout << "IMPOSSIBLE" << endl;
	return 0;
}
