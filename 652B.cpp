#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long> v;
	for(int i = 1; i <= n; ++i){
		long long x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	
	int a = 0; int b = v.size()-1;
	vector<long long> ans;
	while(a != b){
		if(b >= a) {ans.push_back(a); ans.push_back(b);}
		else return cout << "Impossible",0;
		a++; b--;
	}
	
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	return 0;
}
