#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int main(){
	int n;
	cin >> n;
	int mini = INT_MAX;
	int pos = 0;
	int v[10];
	for (int i = 1; i <= 9; ++i)
	{
		cin >> v[i];			
		if(v[i] <= mini){mini = v[i]; pos = i; 	}
	}
	vector<int> ans;
	int d = n/mini;
	int total = n - mini*d;
	for (int i = 0; i < d; ++i)
	{	
		for (int j = 9; j >= 1; --j)
		{
			if(v[j] - mini <= total){
				total -= v[j] - mini;
				ans.push_back(j);
				break;
			}
		}
		if(total <= 0)break;
	}
	while(ans.size()<d) ans.push_back(pos);
	if(ans.size() == 0) cout << -1;
	else for (int i = 0; i < ans.size(); ++i) cout << ans[i];
	return 0;
}