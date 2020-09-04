#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n;
int d[200010];
vector<int> G[200010];
int way[200010];
int distance(int i){
	for (int i = 0; i < 200010; ++i){
		way[i] = -1;
		d[i] = -1;
	}
	queue<int> bfs;
	bfs.push(i);
	d[i] = 0;
	int id = 0;
	int dist = -1;
	while(!bfs.empty()){
		int u = bfs.front();
		bfs.pop();
		if(d[u] > dist){
			id = u;
			dist = d[u];
		}
		for ( int v: G[u]){
			if(d[v] == -1){
				way[v] = u;
				d[v] = d[u] + 1;
				bfs.push(v);
			}
		}
	}
	return id;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--){
		for (int i = 0; i < 200010; ++i) G[i].clear();
	cin >> n;
	for (int i = 0; i < n-1; ++i){
		int x,y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int a = distance(1);
	int b = distance(a);
	
	int ans = 0;
	vector<int> v;
	v.clear();
	while(b != -1){
		v.push_back(b);
		b = way[b];
	}
	int random = 1e7;
	int ans1=1e7,ans2,ans3;
	for (int i = 0; i < v.size()/2; ++i){
		if(i > ans1) break;
		for (int j = v.size()-1; j >= v.size()/2; --j){
			int d1 = i;
			int d2 = j - i-1;
			int d3 = v.size()-j-1;
			int d = max(d1,max(d2,d3));
			if(d < ans1){
				ans1 = d;ans2 = v[i]; ans3 = v[j];
			}
			if(d == ans1 and d2 < random){
				random = d2;
				ans1 = d;ans2 = v[i]; ans3 = v[j];
			}
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3 << endl;
	}
	return 0;
}
