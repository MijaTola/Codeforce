#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;

	cin >> x;
	string dec = "";
	string fac = "";
	int pos = 0;
	bool sw = false;
	if(x[0] == '-'){
		pos = 1;
		sw = true;
	}
	bool ver = false;
	for (int i = pos; i < x.size(); ++i)
	{
		if(!ver){
			if(x[i]!='.') dec+=x[i];
			else ver = true;
		}else fac += x[i];
	}

	string ans1 = "";
	string ans2 = "";
	int c = 0;
	for (int i = dec.size()-1; i >= 0; --i)
	{
		if(c < 3){
			ans1 = dec[i]+ans1;
			c++;
		}else{
			ans1 = ","+ans1;
			ans1 = dec[i] +ans1;
			c = 1;
		}
	}

	while(fac.size() < 2) fac += '0';

	if(fac.size() > 2) fac = fac.substr(0,2);

	if(sw) cout << "($"<< ans1 << "." << fac<<")";
	else cout<<"$" << ans1 << "." << fac;
	

	

	return 0;
}