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
#include <cstdlib>

using namespace std;

typedef long long ll;

int n,m,k;

int v[110];
ll p[110][110];
ll dp[110][110][110];
ll f(int pos, int num, int color){
    if(pos == n){
        if(num == k) return 0LL;
        else return 1e15;
    }
    if(dp[pos][num][color] != -1) return dp[pos][num][color];
    ll ans = 1e15;
    if(v[pos] == 0){
        for (int i = 1; i <= m; ++i){
            if(i == color) ans = min(ans,f(pos+1,num,i)+p[pos][i]);
            else ans = min(ans,f(pos+1,num+1,i)+p[pos][i]);
        }
    }else if(color == v[pos]) ans = min(ans,f(pos+1,num,v[pos]));
    else ans = min(ans,f(pos+1,num+1,v[pos]));
    return dp[pos][num][color] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i  = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j) cin >> p[i][j];
    
    ll ans = f(0,0,0);
    if(ans == 1e15) cout << -1 << endl;
    else  cout << ans << endl;
    return 0;
}

