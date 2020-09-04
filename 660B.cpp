#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int s[110][4];
	memset(s,0,sizeof s);
	int odd = 1;
	int even = 2;
	int total = 0;
	for (int i = 0; i < n; ++i){
		if(total == m) break;
		s[i][0] = odd; odd += 2; total ++;
		if(total== m) break;
		s[i][3] = even; even += 2; total ++;
	}
	for (int i = 0; i < n; ++i){
		if(total == m) break;
		s[i][1] = odd; odd += 2; total++;
		if(total== m) break;
		s[i][2] = even; even += 2; total++; 
	}
	
	for (int i = 0; i < n;++i){
		if(s[i][1] != 0) cout << s[i][1] << " ";
		if(s[i][0] != 0) cout << s[i][0] << " ";
		if(s[i][2] != 0) cout << s[i][2] << " ";
		if(s[i][3] != 0) cout << s[i][3] << " ";
	}
	cout << endl;
	return 0;
}
