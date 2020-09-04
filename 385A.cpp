#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,c,x;
	cin >> n >> c;
	int profit = 0;
	int today;
	int yesterday;
	cin >> yesterday;
	for (int i = 1; i < n; ++i){
		cin >> today;
		int ans = yesterday - today - c;
		profit = max(profit,ans);
		yesterday = today;
	}
	cout << profit << endl;
}