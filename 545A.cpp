#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,x;
	cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		bool sw = true;
		for (int j = 0; j < n; ++j)
		{
			cin >> x;
			if(x == 1 or x == 3) sw = false;
		}
		if(sw) ans.push_back(i+1);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";  
	
	return 0;
}