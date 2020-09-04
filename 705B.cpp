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

using namespace std;

typedef long long ll;

int main(){
    
    int n; cin >> n;
    ll total = 0;
    while(n--){
        ll x; cin >> x;
        total+=x-1LL;
        if(total&1) cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}

