#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> vi;
pair <int,int> ii;
#define pb push_back
#define mp make_pair
char m[15][15];
int main(){
	int r,c,n,k;

	cin >> r >> c >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int x,y;
		cin >> x >> y;
		m[x][y] = '#';
	}
	int ans = 0;
	
	for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j)
		for (int q = i; q <= r; ++ q)  for (int l = j; l <= c; ++l){
					int s = 0;
					for (int a = i; a <= q; ++ a)
						for (int b = j; b <= l; ++ b)
							if(m[a][b] == '#') s++;
					
					if(s >= k) ans++;
		}
			
		
	
	cout << ans;
	return 0;
		
}