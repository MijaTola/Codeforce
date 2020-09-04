#include <iostream>

using namespace std;

char v[100010];
int main(){
	int n,x;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		cin >> v[i]; 
	string ans = "";
	ans += v[x];
	int m; cin >> m;
	char c;
	for (int i = 0; i < m; ++i){
		cin >> c;
		if(c == 'L'){
			x--;
			ans += v[x];
		}else{
			x++;
			ans += v[x];
		}
	}
	cout << ans << endl;
	return 0;
}
