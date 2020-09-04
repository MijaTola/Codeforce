#include <bits/stdc++.h>

using namespace std;

int main(){

	string s;
	string t;

	cin >> s >> t;

	int dist = 0;
	int ds = 0;
	int dt = 0;
	for (int i = 0; i < s.size(); ++i)
		if(s[i] != t[i]) dist++;

	if(dist%2 == 1){
		cout << "impossible"; return 0;
	}
	dist/=2;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == t[i]) cout << s[i];
		else{
			if(dist != 0){
				cout << s[i];
				dist--;
			}else cout << t[i];
		}
	}
	return 0;
}