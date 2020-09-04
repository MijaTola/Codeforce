#include <bits/stdc++.h>

using namespace std;

map<char,int> data;

int convertion(string number,int base){
	int ans = 1*data[number[number.size()-1]];
	int pot = base;
	for (int i = number.size()-2; i >= 0; --i)
	{
		ans += pot*data[number[i]];
		pot *= base;
	}
	return ans;
}
int main(){
	int pos = 0;
	for (int i = '0'; i <= '9'; ++i) {data[i] = pos; pos++;}
	for (int i = 'A'; i <= 'Z'; ++i) {data[i] = pos; pos++;}
	string x;
	int y;
	cin >> x;
	int ini = INT_MAX;
	int end = -1;
	string hour = "";
	string minute = "";
	bool sw = false;
	for (int i = 0; i < x.size(); ++i)
	{
		if(x[i]==':'){
			sw = true; continue;
		}
		if(!sw) hour += x[i];
		else minute += x[i];
	}
	for (int i = 0; i < x.size(); ++i)
		end = max(end,data[x[i]]);
	vector<int> ans;
	for (int i = end+1; i <= 60; ++i)
	{
		int h = convertion(hour,i);
		int m = convertion(minute,i);
		if(h < 24 and m < 60) ans.push_back(i);	
	}

	if(ans.size() == 0) cout << 0;
	else if(ans[ans.size()-1] == 60) cout << -1;
	else{
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << " ";
		
	}
	return 0;	
}