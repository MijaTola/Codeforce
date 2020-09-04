#include <bits/stdc++.h>

using namespace std;


int main(){
	int k;
	int pos[150000];
	int neg[150000];
	vector<int> p;
	vector<int> n;
	cin >> k;
	int t,a;
	for (int i = 0; i < k; ++i)
	{
		cin >> t >> a;
		if(t > 0){ pos[t] = a;p.push_back(t);}
		else {neg[t*(-1)] = a; n.push_back(t*(-1));}
	}
	sort(p.begin(),p.end());
	sort(n.begin(),n.end());
	bool sw = false;
	bool e = false;
	int negn = 0;
	int posp = 0;
	int ans = 0;
	if(p.size() < n.size()) sw = true;
	while(!e){
		if(!sw){
			if(posp >= p.size()) break;
			ans+=pos[p[posp]];
			posp++;
			sw = true;
		}else{
			if(negn >= n.size()) break;
			ans+=neg[n[negn]];
			negn++;
			sw = false;
		}
	}
	cout << ans;
	return 0;
}