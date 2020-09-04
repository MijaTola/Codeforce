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

pair<long long,long long> v[5010];
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    sort(v,v+n);
    long long ans = -1;
    for (int i = 0; i < n; ++i){
        if(ans <= v[i].second) ans = v[i].second;
        else ans = v[i].first;
    }
    cout << ans << "\n";
    return 0;
}
