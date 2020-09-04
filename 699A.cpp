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

ll v[200010];
int main(){
    int n; cin >> n;
    string x;
    cin >> x;
    for (int i = 0; i < n; ++i) cin >> v[i];
    ll ans = 1e14;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == 'R' and x[i+1] == 'L'){
            ll dif = v[i+1]-v[i];
            dif/=2LL;
            ans = min(dif,ans);
        }
    }
    if(ans == 1e14) cout << -1 << endl; 
    else cout << ans << endl;
    return 0;
}

