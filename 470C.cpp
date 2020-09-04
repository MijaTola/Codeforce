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


int v[100010];
int s[100010];
int main(){
    memset(v,-1,sizeof v);
    int n,m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        v[x-1] = 0;
        s[i] = x-1;
    }
    
    return 0;
}

