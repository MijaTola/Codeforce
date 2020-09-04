#include <iostream>

using namespace std;

int main(){
	int n; string x;
	cin >> n >> x;
	
	int ans = -1;
	for (int i = 0; i < n; ++i){
		string y;int p; cin >> y >> p;
		for (int j = 0; j < x.size(); ++j){
		    if(x[j] != y[j]){
		    	if(y[j] != '?') continue;
		    	ans = max(p,ans);
		    }	
		}
	}
	cout << ans << endl;
	return 0;
}
