#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x,y;
	int dx[10000],dy[10000];
	bool visited[10000];
	memset(visited,false,sizeof visited);
	cin >> n >> x >> y;

	for (int i = 0; i < n; ++i)
	{
		cin >> dx[i] >> dy[i];
		dx[i] -= x;
		dy[i] -= y;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i]){
			for (int j = 0; j < n; ++j)
				if (dx[i]*dy[j] - dy[i]*dx[j] == 0)
					visited[j] = true;
			ans++;
		}
	}

	cout << ans;
	return 0;
}