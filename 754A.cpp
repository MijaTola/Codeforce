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

int v[110];
int dp[110];
int n;
vector<pair<int,int> > ans;
int f(int pos){
    if(pos == n+1) return true;
    if(dp[pos] != -1) return dp[pos];
    for (int i = pos; i <= n; ++i)
        if(v[i]-v[pos-1] != 0 and f(i+1)) return dp[pos] = true;
    return dp[pos] = false;
}

void r(int pos){
    if(pos == n+1) return;
    for (int i = pos; i <= n; ++i){
        if(v[i]-v[pos-1] != 0 and f(i+1)){
            ans.push_back({pos,i});
            r(i+1);
            return;
        }
    }
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] += v[i-1];
    }

    if(!f(1)) return cout << "NO\n",0;
    cout << "YES\n";
    r(1);
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}

