#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct cmp{
	bool operator ()(const pair<string,int> a, const pair<string,int> b){
		return a.second < b.second;
	}
};
priority_queue<pair<string,int>,vector<pair<string,int> >, cmp >q[100000];
int main(){
	int n,m; cin >> n >> m;
	for (int i = 0; i < n; ++i){	
		string x; int y,z;
		cin >> x >> y >> z;
		q[y].push(make_pair(x,z));
	}
	
	for (int i = 1; i <= m; ++i){
		string a1 = q[i].top().first;
		int a2 = q[i].top().second;
		q[i].pop();
		string b1 = q[i].top().first;
		int b2 = q[i].top().second; 
		q[i].pop();
		int c = -1;
		if(!q[i].empty()) c = q[i].top().second;
		if(b2 == c)	cout << "?" << endl;
		else{
			cout << a1 << " " << b1 << endl;
		}
	}
}
