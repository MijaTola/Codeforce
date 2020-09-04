#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
pair<ll,ll> v[1000];
bool visited[123];
int pos = 0;
void dfs(int u){
	visited[u] = true;
	for (int i = 1; i <= pos; ++i)
	{
		if(visited[i]) continue;
		if(v[u].first > v[i].first  and  v[u].first < v[i].second) dfs(i);
		else if(v[u].second > v[i].first and v[u].second < v[i].second) dfs(i);
	}	
}
int main(){
	int n;

	cin >> n;
	ll m,x,y;
	memset(visited,false,sizeof visited);
	for (int i = 0; i < n; ++i)
	{
		cin >> m >> x >> y;
		if(m == 1){
			pos++;
			v[pos] = pair<ll,ll>(x,y); 
		}
		
		if(m == 2){
			memset(visited,false,sizeof visited);
			dfs(x);
			if(visited[y]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}