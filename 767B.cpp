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

long long v[100010];
int main(){
    long long s,t,x; cin >>s >> t >> x;
    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v,v+n);

    long long time = s;

    for (int i = 0; i < n; ++i){
        if(time < v[i] and time < t) return cout << time << "\n",0;
        else time  += x;
    }
    long long p = v[0];
    for (int i = 0; i < n; ++i){
        if(p < v[i]) return cout << p << "\n",0;
        else p += x;
    }
    if(time <= t-x) cout << time << "\n";
    else if(v[0] > 0 ) cout << v[0]-1 << "\n";
    return 0;
}
