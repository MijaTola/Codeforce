#include <bits/stdc++.h>

using namespace std;

int main(){

	string a,b;
	cin >> a >> b;
	set<char> aa;
	set<char> bb;
	vector<char> t;
	for (int i = 0; i < a.size(); ++i)
		aa.insert(a[i]);
	for (int i = 0; i < b.size(); ++i)
		bb.insert(b[i]);

	if(aa.size()==bb.size()){
		for (int i = 0; i < a.size(); ++i)
			if(a[i] != b[i]) t.push_back('a');
		
		if(t.size()!= 2){
			cout << "NO"; return 0;
		} 
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(a == b){ cout << "YES"; return 0;}
	}
	cout <<"NO";
	return 0;
}