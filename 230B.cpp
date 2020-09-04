#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 1000000
int main(){
	bool visited[MAX];
	memset(visited,false, sizeof visited);
	for (int i = 2; i*i <= MAX; ++i)
	{
		if(visited[i] == false){
			int c = i;
			while(c <= MAX){
				c += i;
				if(c <= MAX){
				visited[c] = true;
				}
			}
		}
	}
	visited[0] = true;
	visited[1] = true;
	ll n,x;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		double s = sqrt(x);
		int t = (int)s;
	//	cout << t << " " << s << endl;
		if(t != s) cout << "NO";
		else if(!visited[t]) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}