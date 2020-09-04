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

string v[500010];
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    for (int i = 0; i < 500000;++i) v[n] += 'z';

    for (int i = 1; i <= n; ++i){
        int sz = v[i].size();
        int sz1 = v[i-1].size();
        string ans = "";
        for (int j = 0; j < min(sz,sz1); ++j){
            if(v[i][j] < v[i-1][j]) break;
            ans += v[i-1][j];
        }
        cout << ans << "\n";
    }
    
    return 0;
}

