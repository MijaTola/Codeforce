#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<pair<int,int> > l;
	int sum,limit;
	cin >> sum >> limit;
	for (int i = 1; i <= limit; ++i)
		l.push_back(make_pair(i&-i,i));
	

	sort(l.begin(),l.end());

	int s = 0;
	int pos = 0;
	vector<int> ans;
	for (pos = l.size()-1; pos >= 0; --pos)
	{
		if(l[pos].first <= sum){
			sum -=l[pos].first;
			ans.push_back(l[pos].second);
		}
		if(sum <= 0) break;
	}

	if(sum == 0){
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i]<<" ";
	}else cout << -1;
	return 0;
}