#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int n; cin >> n;
	int v[1010];
	for (int i = 0; i < n; ++i) cin >> v[i];
	vector<int> ans;
	for (int i = 1; i < n; ++i){
		if(__gcd(v[i],v[i-1]) != 1){
			ans.push_back(v[i-1]);
			ans.push_back(1);
		}else{
			ans.push_back(v[i-1]);
		}
	}
	ans.push_back(v[n-1]);
	cout <<ans.size() - n << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
