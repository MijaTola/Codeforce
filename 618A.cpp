#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int v[100000];
	memset(v,1,sizeof v);
	cin >> n;
	if(n == 1) {cout << 1; return 0;}
	deque<int> ans;
	ans.push_back(1);
	for (int i = 1; i < n; ++i)
	{
		int x = 1;
		if(ans.back() == x){
			while(ans.back() == x){
			ans.pop_back();
			x++;
			if(ans.empty()) break;
			}
		}

		ans.push_back(x);
	
	}

	while(!ans.empty()){
		cout << ans.front() << " ";
		ans.pop_front();
	}
	return 0;
	
}

