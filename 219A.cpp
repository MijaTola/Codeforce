#include <bits/stdc++.h>

using namespace std;

int main(){

	int k;string s;
	cin >> k >> s;

	int  alpha[26];
	set<char> a;
	memset(alpha,0,sizeof alpha);
	for (int i = 0; i < s.size(); ++i){
			alpha[s[i]-'a']++;
			a.insert(s[i]);
	}
	

	bool sw = true;
	for (std::set<char>::iterator i = a.begin(); i != a.end(); ++i)
		if(alpha[*i-'a']%k!=0){sw = false; break;}

	if(sw){
		string ans = "";
	for (std::set<char>::iterator i = a.begin(); i != a.end(); ++i){
		int d = alpha[*i-'a']/k;
		for(int j = 0; j < d; ++j) ans += *i;
	}
	
	for (int i = 0; i < k; ++i)
		cout << ans;x	
		
	}else cout << -1;
	return 0;
}