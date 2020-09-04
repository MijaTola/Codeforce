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
    
    int a,b,c,d; cin >> a >> b >> c >> d;

    int mn = min(a,min(c,d));
    a -= mn;
    c -= mn;
    d -= mn;
    int ans = 0;
    ans += mn*256;
    mn = min(a,b);
    ans += mn*32;
    cout << ans << endl;
    return 0;
}

