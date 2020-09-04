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

int v[110];
int dp[110][10];
int n;
int f(int pos, int last){
    if(pos == n) return 0;
    if(dp[pos][last] != -1) return dp[pos][last];
    int ans = 1e8;
    if(v[pos] == 0) ans = min(f(pos+1,0)+1,ans);
    if(v[pos] == 1 and last != 1)ans = min(ans,f(pos+1,1));
    if(v[pos] == 2 and last != 2) ans = min(ans,f(pos+1,2));
    if(v[pos] == 3){
        if(last != 2) ans = min(ans,f(pos+1,2));
        if(last != 1) ans = min(ans,f(pos+1,1));
    }
    ans = min(ans,f(pos+1,0)+1);
    
    return dp[pos][last] = ans ;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << f(0,0) << "\n";
    return 0;
}

