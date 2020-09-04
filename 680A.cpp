#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<int,int> m;
int main(){
	
	for (int i = 0; i < 5; ++i){
		int x; cin >> x;
		m[x]++;
	}
	int ans = 1e9;
	for (pair<int,int> x: m){
		int sum = 0;
		for (pair<int,int> y: m){
			if(x.first == y.first and x.second > 1) continue;
			sum += y.first*y.second;
		}
		if(x.second > 3){
			int d = x.second - 3;
			sum += x.first*d;
		}
	//	cout <<x.first << " " << sum << endl;
		ans = min(ans,sum);
	}
	cout << ans <<"\n";
	return 0;
}
