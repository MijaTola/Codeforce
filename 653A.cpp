#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	
	int n;
	vector<int> v;
	bool t[1001];
	memset(t,false,sizeof t);
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		if(!t[x]){
			v.push_back(x);
			t[x] = true;
		}
	}
	
	sort(v.begin(),v.end());
	
	bool sw = false;
	for(int i = 0; i < (int)v.size()-2; ++i){
	//	cout << v[i] << " " << v[i+1] <<  " " << v[i+2] << endl;
		if(v[i] + 1 == v[i+1] and v[i+1] + 1 == v[i+2]){
			sw = true; break;
		}
	}
	if(sw) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
