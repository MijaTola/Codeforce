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

int v[110];
int main(){
    
    int n; cin >> n;
    int mx = -1;
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        mx = max(mx,v[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += abs(v[i]-mx);
    
    cout << ans << "\n";
    return 0;
}

