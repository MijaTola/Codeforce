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
ll v[500010];
int main(){
    int n;cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] += v[i-1];
    }
    
    if(v[n]%3LL!=0) return cout << 0 <<endl,0;
    
    ll cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        if(v[i] == 2*v[n]/3)
            if(i < n) ans += cnt;
        if(v[i] == v[n]/3) cnt++;
    }
    cout << ans << "\n";
    return 0;   
}
