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

int v[200010];

//1 2 3 4 5 6 7
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v,v+n);
    int mn = INT_MAX;
    for (int i = 1; i < n; ++i)
        mn = min(abs(v[i]-v[i-1]),mn);
    int ans = 0;
    for (int i = 1; i < n; ++i)
        if(abs(v[i]-v[i-1]) == mn) ans++;

    cout << mn << " " << ans << "\n";

    return 0;
}

