#include <bits/stdc++.h>

using namespace std;
string s[7] = {"lunes","martes","miercoles","jueves","viernes","sabado","domingo"};
int main(){
	int p = 0,ans2 = 0,ans1 = 0, n;
	cin>>n;
	for(int i = 0; i < n; i++){
		if(s[p] == "sabado" or s[p] == "domingo")
			ans1++;
		p++;
		p = p % 7;
	}
	p = 5;
	for(int i = 0; i < n; i++){
		if(s[p] == "sabado" or s[p] == "domingo")
			ans2++;
		p++;
		p = p % 7;
	}
	cout<< ans1 << " " << ans2 << endl;
	return 0;
}
