#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n,x,y;
	vector<pair<int,int> > w;
	bool walk[1000];
	cin >> n;
	memset(walk,false, sizeof walk);
	for (int i = 0; i < n; ++i)
	 {
	 	cin >> x;
	 	w.push_back(make_pair(x,i));
	 } 

	sort(w.begin(),w.end());
	bool sw = false;
	for (int i = 0; i < w.size(); ++i)
	{
		walk[w[i].second] = true;
		if(walk[0] or walk[w.size()-1])	sw = true;
		
		for (int j = 1; j < w.size(); ++j)
		{
			if(walk[j] and walk[j-1]){
				sw = true; break;
			}
		}
		if(sw) return cout << w[i].first, 0;
	}

	return 0;
}