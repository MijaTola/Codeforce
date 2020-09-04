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

set<int> s;
set<int> vis;
int main(){
    int m;
    long long b,l,q;
    cin >> b>> q >>l >> m;

    for (int i = 0; i < m; ++i){
        int x; cin >> x;
        s.insert(x);
    }
    int ans = 0;
    bool cycle = false;
    bool first = true;
    while(abs(b) <= l){
        if(!first) b *= q;
        first = false;
        if(vis.count(b)){cycle = true; break;}
        vis.insert(b);
        if(!s.count(b) and abs(b) <= l) {
            s.insert(b); ans++;
        }
    }
    if(cycle and ans > 0) cout << "inf\n";
    else cout << ans << "\n";
    return 0;
}

