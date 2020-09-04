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

bool v[10010][2];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    bool flag = false;
    for (int i = 0; i < m; ++i){
        int k; cin >> k;
        bool ans = true;
    memset(v,false,sizeof v);
        while(k--){
            int x; cin >> x;
            if(x < 0) v[abs(x)][1] = true;
            else v[abs(x)][0] = true;
            if(v[abs(x)][0] and v[abs(x)][1]) ans = false;
        }
        flag |= ans;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

