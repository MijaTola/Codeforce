#include <bits/stdc++.h>

using namespace std;

int main(){
	string x;
	getline(cin,x);
	char t;
	for (int i = x.size()-1; i >= 0; --i)
		if(isalpha(x[i])){t = x[i]; break;}
	
	t = toupper(t);
	if(t == 'A' or t == 'E' or t == 'I' or t == 'O' or t == 'U' or t == 'Y') 
		cout << "YES";
	else cout << "NO";
	return 0;
}