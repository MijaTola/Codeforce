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

int n;
long long  v[100010];
long long dp[100010];
long long f(int pos){
    if(pos >=  100001) return 0;
    if(dp[pos] != -1) return dp[pos];
    long long ans = 0;
    ans = max(ans,f(pos+1));
    ans = max(ans,f(pos+2)+v[pos]*pos);
    return dp[pos] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        v[x]++;
    }

    cout << f(1) << "\n";
    return 0;
}

