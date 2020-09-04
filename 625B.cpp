#include <bits/stdc++.h>

using namespace std;

int main(){
	string x,y;

	cin >> x >> y;
	int pos = 0; int ans = 0;
	bool sw = false;
	for (int i = 0; i < x.size(); ++i)
	{
			string t = "";
		for (int j = i; j < y.size()+i; ++j)
			t += x[j];
		if(t == y){
			ans ++;
			i += y.size()-1;
		}
	}
	cout << ans;
	return 0;
}