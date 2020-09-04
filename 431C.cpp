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

typedef long long ll;

int dp[110][110];
int n,k,d;
const int mod =  1e9+7;
int f(int sum, bool flag){
    if(sum == n and flag) return 1;
    if(sum > n) return 0;
    if(dp[sum][flag] != -1) return dp[sum][flag];
    int ans = 0;
    for(int i = 1; i <= k; ++i)
        ans = (ans+f(sum+i,flag or i >= d))%mod;
    return dp[sum][flag] = ans%mod;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n >> k >> d;
    cout << f(0,0) << "\n";
    return 0;
}

