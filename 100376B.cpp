#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

int main(){

	int t; cin >> t;
	while(t--){
		ll n,m,x1,y1,x2,y2;
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		//scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&n,&m,&x1,&y1,&x2,&y2);
		
		ll izq = min(x1-1,x2-1);
		ll abajo = min(n-y1,n-y2);
		ll der = min(m-x1,m-x2);
		ll arriba = min(y1-1,y2-1);
		
		ll left1 = x1-izq;
		ll top1 = y1-arriba;
		ll right1 = x1+der;
		ll down1 = y1+abajo;
		
		ll left2 = x2-izq;
		ll top2 = y2-arriba;
		ll right2 = x2+der;
		ll down2 = y2+abajo;
		
		if(x1 < x2 and y1 < y2){
			if(down1 > top2 and right1 > left2){
				cout << top2 << " " << left2 << " " << down1 << " " << right1 << endl;
			}
		}
		if(x1 > x2 and y1 < y2){
			if(right2 > left1 and down1 > top2){
				cout << top2 << " " << right2 << " " << down1 <<" " << left1 << endl;
			}
		}
		
		if(x2 < x1 and y2 < y1){
			if(right2 > left1 and down2 > top1){
				cout << top1 << " " << left1 << " " << down2 << " " <<right2 << endl;
			}
		}
		if(y2 < y1 and x1 < x2){
			if(right1 > left2 and down2 > top1){
				cout << down2 << " " << left2 << " " << top1 << right1 << endl;
			}
		}
		
		if(y1 == y2){
			if(right1 > left2 or left1 > right2){
				cout << right1 << " " << down1 << " " << top2 << " " <<left2 << endl;
			}
		}
		
		if(x1 == x2){
			if(down1 > top2 or down2 > top1){
			
			}
		}
	}
}










/*int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct hand{
	ll x1,y1,x2,y2;
	hand(){}
	hand(ll x,ll y,ll a, ll b){
		x1 = x;
		y1 = y;
		x2 = a;
		y2 = b;
	}
};
set<pair<int,int> > vis;
ll n,m;
bool f(ll a, ll b , ll x, ll y){
	return a >= 1 and a <= n and b >= 1 and b <= m and x >= 1 and x <= n and y >= 1 and y <= m and (!vis.count({a,b}) or !vis.count({x,y}));
}
int main(){
	
	int k; //cin >> k;
	scanf("%d",&k);
	while(k--){
		vis.clear();
		ll x1,y1,x2,y2;
		ll ans = 2;
		queue<hand> q;
		//cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&n,&m,&x1,&y1,&x2,&y2);
		q.push(hand(x1,y1,x2,y2));
		vis.insert({x1,y1});
		vis.insert({x2,y2});
		while(!q.empty()){
			ll a = q.front().x1;
			ll b = q.front().y1;
			ll s = q.front().x2;
			ll t = q.front().y2;
			q.pop();
			for (int i = 0; i < 4; ++i){
				ll da = dx[i] + a;
				ll db = dy[i] + b;
				ll ds = dx[i] + s;
				ll dt = dy[i] + t;
				if(f(da,db,ds,dt)){
					if(!vis.count({da,db})){
						ans++;
						vis.insert({da,db});
					}
					if(!vis.count({ds,dt})){
						ans++;
						vis.insert({ds,dt});
					}
					q.push(hand(da,db,ds,dt));
					
				}
			}
		}
		ll total = n*m;
		//cout << total - ans << endl;
		printf("%I64d\n",total-ans);
	}
	return 0;
}*/
