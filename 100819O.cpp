#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int r[500][500];
int d[500][500];
int n,m; 
bool check(int x,int y){
	if(x >= 0 and x < n and y >= 0 and y < m and d[x][y] == -1) return true;
	return false;
}
int main(){
	memset(d,-1,sizeof d);
	queue<pair<int,int> > bfs;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			char p; cin >> p;
			r[i][j] = p - '0';
		}
			
			
	bfs.push(make_pair(0,0));
	d[0][0] = 0;
	bool flag = false;
	while(!bfs.empty()){
		int x = bfs.front().first;
		int y = bfs.front().second;
		bfs.pop();
		if(x == n-1 and y == m-1){
			cout << d[x][y] << endl;
			flag = true;
			break;
		}
		int u,v;
		u = x + r[x][y];
		v = y;
		if(check(u,v)){
			d[u][v] = d[x][y] +1;
			bfs.push(make_pair(u,v));
		}
		u = x - r[x][y];
		v = y;
		if(check(u,v)){
			d[u][v] = d[x][y] +1;
			bfs.push(make_pair(u,v));
		}
		u = x;
		v = y + r[x][y];
		if(check(u,v)){
			d[u][v] = d[x][y] +1;
			bfs.push(make_pair(u,v));
		}
		u = x;
		v = y - r[x][y];
		if(check(u,v)){
			d[u][v] = d[x][y] +1;
			bfs.push(make_pair(u,v));
		} 
	}
	if(!flag) cout << "IMPOSSIBLE" << endl;
	return 0;
}
