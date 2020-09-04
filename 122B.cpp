#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	map<string,int> m;
	cin >> s;
	int fr = 0;
	int svn = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '4') fr++;
		else if(s[i] == '7') svn++;
	}
	if(fr == 0 and svn == 0) cout << -1;
	else{
		if(svn > fr) cout << 7;
		else cout << 4;
	}
	return 0;
}