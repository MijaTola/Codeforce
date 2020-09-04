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


int n1,n2,k1,k2;
const int mod = 100000000;

int dp[110][110][12][12];
int f(int p1,int p2,int r1,int r2){
    if(p1 == n1 and n2 == p2) return 1;
    if(dp[p1][p2][r1][r2] != -1) return dp[p1][p2][r1][r2];
    int ans = 0;
    if(p1 < n1 and r1 < k1) ans = (ans +f(p1+1,p2,r1+1,0))%mod;
    if(p2 < n2 and r2 < k2) ans = (ans +f(p1,p2+1,0,r2+1))%mod;
    return dp[p1][p2][r1][r2] = ans%mod;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n1 >> n2 >> k1 >> k2;
    cout << f(0,0,0,0) << endl;;
    return 0;
}

