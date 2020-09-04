#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
int v[30];
int main(){
	string x; cin >> x;
	for (int i = 0; i < x.size(); ++i){
		v[x[i]-'a']++;
	}
	
	for (int i = 0; i < 30; ++i){
		if(v[i]!= 0) a.push_back(v[i]);
	}
	sort(a.rbegin(),a.rend());
	int ans = 0;
	for (int i = 2; i < a.size(); ++i){
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}

