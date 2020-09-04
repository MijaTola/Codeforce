#include <bits/stdc++.h>

using namespace std;

int main(){
	set<int> x;
	set<int> y;
	int n;cin >> n;
	int a,b;
	while(n--){
		cin >> a >> b;
		x.insert(a);
		y.insert(b);
	}

	if(x.size() < y.size()) cout << x.size();
	else cout << y.size();
	return 0;
}