#include <bits/stdc++.h>

using namespace std;


int main(){
	int n;
	string x;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		getline(cin,x);
		if(x.size() < 5){
			cout << "OMG>.< I don't know!" << endl;
			continue;
		}
		int l = x.size() - 5;
		string lala = x.substr(l,x.size());
		string rain = x.substr(0,5);
		bool swf = false;
		bool swr = false;
		if(lala == "lala.") swf = true;
		if(rain == "miao.") swr = true;
		if(swr and swf) cout << "OMG>.< I don't know!" << endl;
		else if(swr) cout << "Rainbow's" << endl;
		else if(swf)cout << "Freda's" << endl;
		else cout << "OMG>.< I don't know!" << endl;
	}	
	return 0;
}