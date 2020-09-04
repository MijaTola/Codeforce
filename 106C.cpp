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

int dp[1000010];
vector<int> ans;
int f(int u){
    if(u == 0) return 0;
    if(u < 0) return 1e9;
    if(dp[u] != -1) return dp[u];
    int ans = 1e9;
    ans = min(ans,f(u-4)+1);
    ans = min(ans,f(u-7)+1);
    return dp[u] = ans;
}

void rec(int u){
    if(u == 0 or u < 0) return;
    int ans1 = dp[u-4];
    int ans2 = dp[u-7];
    if(ans1 < ans2){
        ans.push_back(4);
        rec(u-4);
    }else{
        ans.push_back(7);
        rec(u-7);
    }
}
int main(){
    memset(dp,-1,sizeof dp);
    int n; cin >> n;
    if(f(n) == 1e9) return cout << "-1\n",0;
    rec(n);
    sort(ans.begin(),ans.end());
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i];
    cout<<"\n";
    return 0;
}

