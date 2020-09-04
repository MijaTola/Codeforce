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

int main(){
    ll t,s,x; 
    cin >> t >> s >> x;
    ll a = -1,b = 1e10;

    while(b- a > 1){
        ll mid = (a+b)/2LL;
        if(t+mid*s >= x) b = mid;
        else a = mid;
    }
    if((x == t+a*s or x == t+b*s or x == t+a*s+1 or x == t+b*s+1) and x != t+1 and x >= t) cout << "YES" << endl;
    else cout << "NO" << endl;
   // cout << t+a*s << " " << t+b*s << endl;
    return 0;
}

