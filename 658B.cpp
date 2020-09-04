#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int v[150020];
	int n,k,l;
	cin >> n >> k >> l;
	bool vis[150000];
	for (int i = 1; i <= n; ++i) cin >> v[i];
	memset(vis,false,sizeof vis);
	priority_queue<int> q;
	while(l--){
		int c,id;
		cin >> c >> id;
		if(c == 1){
			vis[id] = true;
			q.push(-1*v[id]);
			if(q.size()>k) q.pop();
		}else{
			if(!vis[id]) cout << "NO" << endl;
			else{
				if(v[id] >= abs(q.top())) cout << "YES"  << endl;
				else cout << "NO" << endl; 
			}
		}
	}
	return 0;
}
