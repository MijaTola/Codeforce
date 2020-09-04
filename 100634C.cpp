#include <iostream>

using namespace std;

int main(){
	int v[101][101];
	int n,m,c;
	cin >> c >> n >> m;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(v[i][j] == 1) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
	return 0;
}
