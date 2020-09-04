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

typedef long long ll;

int main(){
    ll l1,r1,l2,r2,k;
    cin >> l1 >>r1;
    cin >> l2 >> r2 >> k;

    ll x = max(l1,l2);
    ll y = min(r1,r2);

    if(x > y) cout << 0 << endl;
    else{
        ll a = y - x+1;
        if(x <= k and k <= y) a--;
        cout << a << endl;
    }
    return 0;
}

