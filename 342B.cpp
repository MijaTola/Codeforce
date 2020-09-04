#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	map<ll,bool> control;
	map<ll, pair<int,int> > a;
	int n,m,s,f,l,r;
	cin >> n >> m >> s >> f;
	ll t;
	for (int i = 0; i < m; ++i)
	{
		cin >> t >> l >> r;
		control[t] = true;
		a[t] = pair <int,int>(l,r);
	}
	
	ll step = 1;
	ll pos = s;
	string ans = "";
	while(true){
		if(!control[t]){
			if(s > f){ 
				pos--;
				ans += 'L';
			}else{
			 	pos++;
			 	ans += 'R';
			}
			step++;
		}else{
			if(pos >= a[step].first and pos <= a[step].second) ans += 'X';
			else{
				if(s > f){
					if(pos-1 >= a[step].first and pos-1 <= a[step].second){
						ans +='X'; 
					}else{
					pos--;
					ans += 'L';}
				}else{
					if(pos+1 >= a[step].first and pos+1 <= a[step].second){
						ans +='X'; 
					}else{
			 		pos++;
			 		ans += 'R';}
				}
			}
			step++;
		}
		if(pos == f) break;
	}
	cout << ans;
	return 0;
}