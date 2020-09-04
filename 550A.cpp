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

string x;
int dp[100010][2][2];
int f(int pos, bool a, bool b){
    if(pos == (int)x.size()){
        if(a+b == 2) return 1;
        return 0;
    }
    if(dp[pos][a][b] != -1) return dp[pos][a][b];
    int ans = 0;
    if(x[pos] == 'A' and x[pos+1] == 'B') ans |= f(pos+2,1,b);
    if(x[pos] == 'B' and x[pos+1] == 'A') ans |= f(pos+2,a,1);
    ans |= f(pos+1,a,b);
    return dp[pos][a][b] =ans;
}

int main(){
    memset(dp,-1,sizeof dp);
    cin >> x;
    if(f(0,0,0)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

