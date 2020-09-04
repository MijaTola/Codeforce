#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,x;
	int l[100][100];
	int ans[100][100];
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			ans[i][j] = 1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> l[i][j];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(l[i][j] == 0){
				for(int k = 0;k < m;++k) ans[i][k] = 0;
				for(int k = 0;k < n;++k) ans[k][j] = 0;
			}


	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(l[i][j] == 1){
				bool sw = false;
				for(int k = 0;k < n;++k) if(ans[i][k] == 1) sw = true;
				for(int k = 0;k < m;++k) if(ans[k][j] == 1) sw = true;
				if(!sw){
					cout << "NO"; return 0;
				}
			}
	cout << "YES" << endl;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j) cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}