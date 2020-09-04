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

int n,m;
const int MOD = 1e9+7;
set<char> s[123];
int main(){
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            char x; cin>> x;
            s[j].insert(x);
        }
    
    long long ans = 1LL;
    for (int i = 0; i < m; ++i)
        ans = (ans % MOD * s[i].size() % MOD) % MOD;
    
    cout << ans << "\n";
    return 0;
}

