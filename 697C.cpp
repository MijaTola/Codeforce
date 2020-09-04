#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>

using namespace std;

typedef long long ll;

map<pair<ll,ll>,ll> w;
int main(){
    int q; cin >> q;
    while(q--){
        ll c,u,v;
        cin >> c >> u >> v;
        if(c == 1){
			ll p; cin >> p;
			while(u != v){
				if(u > v) {
					//cout << u << " " << u/2 << endl;
					w[pair<ll,ll>(u,u/2)] += p;
					w[pair<ll,ll>(u/2,u)] += p;
					u/=2LL;
				}else{
					//cout << v << " " << v/2 << endl;
					w[pair<ll,ll>(v,v/2) ]+= p;
					w[pair<ll,ll>(v/2,v) ]+= p;
					v/=2LL;
				}
			}
		}else{
			ll ans = 0LL;
			while(u != v){
				if(u > v) {
					ans += w[pair<ll,ll>(u,u/2)];
					u/=2LL;
				}else{
					ans += w[pair<ll,ll>(v,v/2)];
					v/=2LL;
				}
			}
			cout << ans << endl;
		}
    }
    return 0;
}

