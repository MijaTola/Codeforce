#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp{
	bool operator () (const string a, const string b){
		return a.size() > b.size();
}
};
string process(string x){
	string ans = "";
	for (int i = 0; i < x.size(); ++i)
		if(isalpha(x[i])) ans += tolower(x[i]);
	return ans;
}
int main(){
	vector<string> v;
	string a,b,c;
	cin >> a >> b >> c;
	a = process(a);
	b = process(b);
	c = process(c);
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(),v.end());
	string ab = a+b+c;
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		string x; cin >> x;
		x = process(x);
		if(x == a+b+c or x == a+c+b or x == b+c+a or x == b+a+c or x == c+a+b or x ==c+b+a) cout << "ACC" << endl;
		else cout << "WA" << endl;
	}
	return 0;
}
