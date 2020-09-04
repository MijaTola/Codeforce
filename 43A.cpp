#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	map<string,int> winner;
	for (int i = 0; i < n; ++i)
	{
		string x; cin >> x;
		winner[x]++;
	}
	string win;
	int maxi= -1;
	for (std::map<string,int>::iterator i = winner.begin(); i != winner.end(); ++i)
	{
		if(i->second > maxi){
			maxi = i->second;
			win = i->first;
		}
	}
	cout << win;
	return 0;
}