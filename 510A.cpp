#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n,m;
	char p[51][51];
	memset(p,'.',sizeof p);
	cin >> n >> m;
	bool sw = false;
	for (int i = 0; i < n; ++i)
	{
		if(i%2==0) for (int j = 0; j < m; ++j){
			p[i][j] = '#';
			cout << p[i][j];
		}else{
			if(sw) p[i][0] = '#',sw = false;
			else p[i][m-1] = '#',sw = true;
			for (int j = 0; j < m; ++j)cout <<p[i][j];
		}
		cout << endl;
	}
	return 0;
}