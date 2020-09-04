#include <iostream>
#include <stdlib.h>
#include <set>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	set<int> x;
	set<int> y;
	int n,a,b;	
	cin >> n;
	while(n--){
		cin >> a >> b;
		x.insert(a);
		y.insert(b);
	}

	if(x.size() == 1 || y.size() == 1) cout << -1 << endl;
	else cout << (*(++x.begin()) - *x.begin()) * (*(++y.begin()) - *y.begin()) <<endl;
	return 0;
}