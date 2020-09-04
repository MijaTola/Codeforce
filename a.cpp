#include <bits/stdc++.h>

using namespace std;
const int INF = 100005;
int d[INF];
int v[INF];
bool es[INF];
int vis[INF];
int nodos;
vector<pair<int,int> > grafo[100005];
vector<int> hoteles;
vector<int> G[100005];

void init(int n){	
	hoteles.clear();
	for(int i = 0; i <= n ;i++){
		d[i] = INF * 2;
		G[i].clear();
		grafo[i].clear();
	}
}

void dijkstra(int ini){
	priority_queue<pair<int,int> > q;
	for(int i = 0; i <= nodos; ++i){
		d[i] = INF;
		v[i] = false;
	}
	d[ini] = 0;
	q.push(make_pair(0,ini));
	while(!q.empty()){
		int act = q.top().second;
		q.pop();
		if(v[act])
			continue;
		v[act] = true;
		for(int i = 0; i < grafo[act].size(); ++i){
			int ady = grafo[act][i].first;
			int peso = grafo[act][i].second;
			if(!v[ady] && d[act] + peso < d[ady] ){
				d[ady] = d[act] + peso;
				q.push(make_pair(-d[ady],ady));
			}
		}			
	}
}

int bfs(){
	memset(vis,-1,sizeof(vis));
	queue<int> q;
	q.push(1);
	vis[1] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			if(vis[v] == -1){
				vis[v] = vis[u] + 1;
				q.push(v);
			}
		}
	}
	return vis[nodos];
}
int main(){
	int h,tmp,aux,a,b,c,p;
	while(cin>>nodos and nodos){
		init(nodos);
		memset(es,false,sizeof(es));
		cin>>h;
		for(int i = 0; i < h; i++){
			cin>>tmp;
			hoteles.push_back(tmp);
			es[tmp] = true;
		}
		cin>>h;
		for(int i = 0; i < h; i++){
			cin>>a>>b>>p;
			grafo[a].push_back(make_pair(b,p));
			grafo[b].push_back(make_pair(a,p));
		}
		for(int i = 0; i < hoteles.size(); i++){
			dijkstra(hoteles[i]);
			for(int j = 1; j <= nodos; j++){
				if(d[j] <= 600 and es[j]){
					G[i].push_back(j);
					G[j].push_back(i);
				}else{
					if((j == 1 or j == nodos) and (d[j] <= 600 )){
						G[i].push_back(j);
						G[j].push_back(i);	
					}
				}
			}
		}
		int ans = bfs();

		cout<<bfs()<<endl;
	}	
	return 0;
}