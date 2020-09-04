#include <bits/stdc++.h>

using namespace std;


int main(){
	string a,b;
	cin >> a >> b;
	bool sw = false;
	bool st = false;
	for (int i = 0; i < a.size(); ++i)
		if(a[i] != '0'){
			sw = true;
			a = a.substr(i,a.size());
			break;
		}

	for (int i = 0; i < b.size(); ++i)
		if(b[i] != '0'){
			st = true;
			b = b.substr(i,b.size());
			break;
		}
				if(!sw) a = "0";
		if(!st) b = "0";
	if(a.size() == b.size()){
		if(a > b) cout << ">";
		else if(a < b) cout << "<";
		else cout << "=";
	}else if(a.size() > b.size()) cout << ">";
	else cout << "<";

	
	return 0;
}