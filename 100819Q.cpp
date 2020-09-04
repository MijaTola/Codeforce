#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int main(){
	int n; cin >> n;
	for (int i = 0; i < n;++i){
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int ans = 1e7;
	for (int i = 0; i < n/2; ++i){
		cout << v[i] << " " << v[n-i-1] << endl;
		ans = min(ans,v[i]+v[n-i-1]);
	}
	cout << ans << endl;
	return 0;
}
