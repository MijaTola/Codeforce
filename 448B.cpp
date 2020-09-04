#include <bits/stdc++.h>

using namespace std;

int main(){
	string s,t,ds,dt;
	cin >> s >> t;
	ds = s;
	dt = t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());

	bool sw = true;
	int pos = 0;
	string nw = "";

	for (int i = 0; i < s.size(); ++i)
		if(t[pos] == s[i]){nw += t[pos]; pos++;}
	if(nw == t){
		if(s.size() == t.size()) cout << "array";
		else{
			string a = ""; int p = 0;
			for (int i = 0; i < s.size(); ++i)
				if(ds[i] == dt[p]){a+=ds[i]; p++;}
			if(a == dt) cout << "automaton";
			else cout << "both";
		}
	}else cout << "need tree";
	return 0;
}