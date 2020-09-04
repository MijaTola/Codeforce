#include <bits/stdc++.h>

using namespace std;

int t;
int m[123][4];
string nms[123];
int solve(string x){
	set<char> a;
	bool sw = true;
	char c = ':';
	for (int i = 0; i < x.size(); ++i){
		if(x[i] != '-'){
			a.insert(x[i]);
			if(c > x[i]) c = x[i];
			else sw = false;
		}
	}

	if(a.size() == 1) return 0;
	else if(sw) return 1;
	else return 2;

}

string show(int j,int mx){
	string ans = "";
	bool sw = false;
	for (int i = 0; i < t; ++i)
	{	
		if(m[i][j] == mx){
			if(!sw){ ans+= nms[i]; sw = true;}
			else{
				ans += ", ";
				ans += nms[i];
			}
		}
	}
	ans += '.';
	return ans;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	int s;
	string name,x;
	int mxt = -1;
	int mxp = -1;
	int mxg = -1;
	for (int j = 0; j < t; ++j){
		cin >> s >> nms[j];
		for (int i = 0; i < s; ++i)
		{
			cin >> x;
			m[j][solve(x)]++;
		}
		mxt = max(mxt,m[j][0]);
		mxp = max(mxp,m[j][1]);
		mxg = max(mxg,m[j][2]);
	}	
	string ans1 = show(0,mxt);
	string ans2 = show(1,mxp);
	string ans3 = show(2,mxg);
	cout << "If you want to call a taxi, you should call: "<< ans1 << endl;
	cout << "If you want to order a pizza, you should call: "<< ans2 << endl;
	cout << "If you want to go to a cafe with a wonderful girl, you should call: "<< ans3 << endl;
	return 0;
}