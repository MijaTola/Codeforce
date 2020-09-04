#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;

	int mid = (m+1)/2;
	int x = mid;
	if(m&1){

	for (int i = 0; i < n; ++i)
	{
		cout << x << endl;
		if(x < mid) x = m - x + 1;
		else x = m - x;
		if(x == 0) x = mid;
	}	

	}else{

	for (int i = 0; i < n; ++i)
	{
		cout << x << endl;
		if(x <= mid) x = m - x + 1;
		else x = m - x;
		if(x == 0) x = mid;
	}
	}
	

	return 0;
}