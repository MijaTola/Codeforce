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
#include <unordered_set>
#include <unordered_map>

using namespace std;

string v[55];
int dp[55][2][2][2];
int n,m;
int f(int pos, bool vw, bool dg, bool sb){
    if(pos == n){
        if(vw+dg+sb == 3) return 0;
        else return 1e9;
    }

    if(dp[pos][vw][dg][sb] != -1) return dp[pos][vw][dg][sb];
    int ans = 1e9;
    for (int i = 0; i < (int)v[pos].size(); ++i){
        string x = v[pos];
        int sz = x.size();
        if(x[i]-'a' >= 0 and x[i]-'a'<= 27)  ans = min(ans,f(pos+1,true,dg,sb)+min(i,sz-i));
        if(isdigit(x[i])) ans = min(ans,f(pos+1,vw,true,sb)+min(i,sz-i));
        if(x[i] == '#' or x[i] == '*' or x[i] == '&')
            ans = min(ans,f(pos+1,vw,dg,true)+min(i,sz-i));
    }
    return dp[pos][vw][dg][sb] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << f(0,0,0,0) << "\n";
    return 0;
}

