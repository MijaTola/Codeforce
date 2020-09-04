#include <iostream>
#include <vector>

using namespace std;

char ma[60][60];
vector<pair<int,int> > pos;
int n,m;
int main(){
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i){
	    for (int j = 0; j < m; ++j){
	    	cin >> ma[i][j];
		if(ma[i][j] == 'B')
		   pos.push_back(make_pair(i,j));
	    }
	}
	bool sw = true;
	for (int i = 0; i < pos.size(); ++i){
	    int x = v[i].first;
	    int y = v[i].second;
	    for (int j = 0; j < pos.size(); ++j){
	    	if (i == j) continue;
		int u = v[j].first;
		int v = v[j].second;
		for (int k = min(u,x); k < max(u,x); ++k){
		    if(ma[k][y] != 'B') sw = false, break;
		}
	    }
	}
	return 0;
}
