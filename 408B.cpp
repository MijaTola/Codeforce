#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	string z;
	int alpha[27];
	int needed[27];
	bool visited[27];
	memset(visited,false,sizeof visited);
	memset(alpha,0,sizeof alpha);
	memset(needed,0,sizeof needed);
	cin >> x;

	for (int i = 0; i < x.size(); ++i)
		alpha[x[i]-97]++;

	cin >> z;
	for (int i = 0; i < z.size(); ++i)
		needed[z[i]-97]++;

	int ans = 0;
	for (int i = 0; i < z.size(); ++i)
	{
		if(visited[z[i]-97]) continue;
		if(alpha[z[i]-97] == 0){
			cout << -1; return 0;
		}
		if(alpha[z[i]-97] < needed[z[i]-97]){
			ans += alpha[z[i]-97];
			visited[z[i]-97] = true;
		}else if(alpha[z[i]-97] >= needed[z[i]-97]){
			ans += needed[z[i]-97];
			visited[z[i]-97] = true;
		}
	}
	cout << ans;
	return 0;
}