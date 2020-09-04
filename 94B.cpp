#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int main(){

	vi graph[100];

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= 5; ++i) 
		if(graph[i].size() >= 3 or graph[i].size() <= 1) return cout << "WIN",0;
	
	cout << "FAIL";
	return 0;
}