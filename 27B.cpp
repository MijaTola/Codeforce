#include <iostream>
#include <vector>

using namespace std;

int v[51];
int wons[51];
int main(){
	int n; cin >> n;
	for (int i = 0; i < (n*(n-1)/2)-1; ++i){
		int x,y; cin >> x >> y;
		v[x]++;v[y]++;wons[x]++;
	}
	vector<int> ans;
	for (int i = 1; i <= n; ++i)
		if(v[i] < n-1) ans.push_back(i);
		
	if(wons[ans[0]] >= wons[ans[1]]) cout << ans[0] << " " << ans[1] << endl;
	else cout << ans[1] << " " << ans[0] << endl;
	return 0;
}
