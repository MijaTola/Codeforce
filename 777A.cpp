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

int v[3];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(v,0,sizeof 0);
    int n; cin >> n;
    int x; cin >> x;
    n%=6;
    v[x] = 1;
    for (int i = n; i >= 1; --i){
        if(i&1) swap(v[0],v[1]);
        else swap(v[2],v[1]);
    }

    for (int i = 0; i < 3; ++i)
        if(v[i]) return cout << i << "\n",0;
    return 0;
}

