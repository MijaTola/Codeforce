#include <iostream>
#include <vector>

using namespace std;

vector<pair<string,int> > v;
int main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		string x;int y;
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	int ans = 0;
	for (int i = 1; i <= 100; ++i){

		bool flag = true;
		int p = i;
		for (int j = 0; j < v.size(); ++j){
			if(v[j].first == "ADD") p += v[j].second;
			if(v[j].first == "SUBTRACT") p -= v[j].second;
			if(v[j].first == "MULTIPLY") p *= v[j].second;
			if(v[j].first == "DIVIDE"){
				if(p%v[j].second != 0){
					flag = false; break;
				}
				p /= v[j].second;
			}
			if(p < 0){
				flag = false; break;
			}
		}
		if(!flag) ans++; 
	}
	cout << ans << endl;
	return 0;
}
