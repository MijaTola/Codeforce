#include <iostream>
#include <vector>

using namespace std;
vector<pair<int,int > > p;
char ma[60][60];
int n,m;

bool verify(int x,int y, int u,int v){
	for (int i = min(x,u); i <=  max(x,u); ++i){
	// 	cout << ma[i][y] << " ";
		  if(ma[i][y] != 'B') return false;
	}
	//cout << endl;
	for (int i = min(y,v); i <=  max(y,v); ++i){
	    //	cout << ma[u][i] << " ";
		 if(ma[u][i] != 'B') return false;
	}
//	cout << endl;
	return true;	
}
int main(){
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> ma[i][j];
			if(ma[i][j]=='B') p.push_back(make_pair(i,j));
		}	
	}
	
	for (int i = 0; i < p.size(); ++i){
	    int x = p[i].first;
	    int y = p[i].second;
	    for (int j = 0; j < p.size(); ++j){
		if(i == j) continue;
		int u = p[j].first;
		int v = p[j].second;
//		cout << x << " " << y << " " << u << " " << v << endl;
		if(verify(x,y,u,v)) continue;
//		cout << "afdadsf s " << endl;
		if(verify(u,v,x,y)) continue;
		return cout << "NO" << endl,0; 
	    }
	}
	
	cout << "YES" <<endl;
	return 0;
}
