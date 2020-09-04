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

int main(){
    int n,m; cin >> n >> m;
    
    int mex = 1e9;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        mex = min(y-x+1,mex);
    }
    
    cout << mex << "\n";
    for (int i = 1; i <= n; ++i) cout << i%mex << " ";
    return 0;
}

