#include <iostream>

using namespace std;
int v[102];
int main(){
	
	int n,k; 
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		string x; int y;
		cin >> y >> x;
		if(x == "SAFE"){
			for (int j = 1; j <= y; ++j)
				v[j] = 2;
		}else{
			for (int j = y; j <= k; ++j)
				v[j] = 1;
		}
	}

	int ans = 1; int ans2 = k;
	while(v[ans+1] != 1 and ans+1 <= k) ans++;
	while(v[ans2-1] != 2 and ans2-1 >= 1) ans2--;
	
	if(ans == k) ans--;
	if(ans2 == 1) ans2++;
	
	cout << ans2 << " " << ans << endl;
	return 0;
	
}
