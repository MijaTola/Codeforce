#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	set<string> p;
	cin >> x;
	for (int i = 0; i <= x.size(); ++i)
		for(char j = 'a'; j <= 'z';++j){
			char tmp[5] = {};
			tmp[0] = j;
			string ts = x;
			ts.insert(i, tmp);
			p.insert(ts);
		}

	cout << p.size();
	return 0;
}