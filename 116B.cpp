#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int main(){
	char m[10][10];
	int n,t;
	stack<pair<int,int> > w;
	int pigs = 0;

	cin >> n >> t;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < t; ++j)
		{
			cin >> m[i][j];
			if(m[i][j] == 'W') w.push(make_pair(i,j));
			else if(m[i][j] == 'P') pigs++;
		}
	}

	int ans = 0;
	while(!w.empty() and pigs != 0){
		int x = w.top().first;
		int y = w.top().second;
		w.pop();
		for (int i = 0; i < 4; ++i)
		{
			int c = x+dx[i];
			int d =  y+dy[i];
			if(c >= 0 and c < n and d >= 0 and d < t)
				if(m[c][d] == 'P'){
					pigs--;
					m[c][d] = '.';
					ans++;
					break;
				}
		}
	}
	cout << ans;
	return 0;
}