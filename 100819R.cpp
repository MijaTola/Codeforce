#include <iostream>
#include <set>

using namespace std;
set <pair<string,string> > a;
int main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		string x,y; cin >> x >> y;
		a.insert(make_pair(y,x));
	}
	for (auto x: a)
		cout << x.second << " " <<x.first << endl;
	return 0;
}
