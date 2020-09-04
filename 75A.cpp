#include <bits/stdc++.h>

using namespace std;

int conver(string y){
	stringstream str(y);
	int p;
	str >> p;
	return p;
}
int del(string y){
	string ns = "";
	for (int i = 0; i < y.size(); ++i)
		if(y[i] != '0') ns += y[i];
	return conver(ns);
}
string conver(int y){
	stringstream ss;
	ss << y;
	string p = ss.str();
	return p;
}
int main(){
	string a;
	string b;
	cin >> a >> b;
	int da = conver(a);
	int db = conver(b);
	int dc = da + db;
	string ddc = conver(dc);
	int dda = del(a);
	int ddb = del(b);
	int result2 = del(ddc);
 	int result = dda + ddb;
 	
	if(result == result2) cout <<"YES";
	else cout <<"NO";
	return 0;
}