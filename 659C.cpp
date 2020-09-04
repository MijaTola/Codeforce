#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
typedef long long ll;
string conv(int t){
	stringstream ss;
	ss << t;
	string p = ss.str();
	return p;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	map<ll,bool> v;
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		ll x; cin >> x;
		v[x] = true;
	}
	ll pos = 1LL;
	string a = "";
	ll ta = 0;
	while(m >= 0){
		if(v[pos] == true){
			pos++;
			continue;
		} 
		if(m - pos >= 0){
			string l = conv(pos);
			a += l;
			a += " ";
			ta++;
		} else break;
		m-=pos;
		pos++;
		
	}
	cout << ta << endl;
	cout << a << endl;
	return 0;
}
