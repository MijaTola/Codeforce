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
    int n,b,d; cin >> n >> b >> d;
    int ans = 0;
    int s = 0;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x > b) continue;
        if(s + x > d) ans++, s = 0;
        else s += x;
    }
    cout << ans << endl;
    return 0;
}

