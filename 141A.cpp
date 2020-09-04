#include <bits/stdc++.h>

using namespace std;

int main(){
	string x,y,z;

	cin >> x >> y >> z;

	if(x.size() + y.size() < z.size() or x.size() + y.size() > z.size()) return cout << "NO",0;
	
	
	string p = x+y;

	sort(p.begin(),p.end());
	sort(z.begin(),z.end());

	bool sw = true;
	for (int i = 0; i < p.size(); ++i)
		if(p[i] != z[i]){
			sw = false; break;
		}
	if(sw) cout << "YES";
	else cout << "NO";

	return 0;
}