#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	cin >> x;
	int n,i,t,e,ans;
	n = i = t = e = ans = 0;
	for (int j = 0; j < x.size(); ++j)
	{
		if(x[j] == 'n') n++;
		if(x[j] == 'i') i++;
		if(x[j] == 't') t++;
		if(x[j] == 'e') e++; 
	}
	n-= 3; i -= 1; t-= 1; e -= 3;
	if(n >= 0 and i >= 0 and e >= 0 and t >= 0) ans++;

	if(n >= 2 and i>=i and e >= 3 and t >= 1) ans+=min(min(n/2,i),min(e/3,t));

	cout << ans;
	return 0;
}