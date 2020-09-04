#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,x;
	vvi s(100001);
	vii ans;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		s[x].push_back(i);
	}
	for (int i = 1; i <= 100000; ++i)
	{
		if(s[i].size() == 1){ ans.push_back(make_pair(i,0)); continue;}
		else if(s[i].size() > 1){
			int dis = s[i][1] - s[i][0];
			bool sw = false;
			for (int j = 2; j < s[i].size(); ++j){
				if(s[i][j] - s[i][j-1] != dis){
					sw = true;
					break;
				}
		}
		if(!sw) ans.push_back(make_pair(i,dis));
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}

