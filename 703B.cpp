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

int v[100010];
bool vis[100010];
int main(){
    memset(vis,false,sizeof vis);
    int n,k; cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) sum += v[i]*v[i-1];
    sum += v[0]*v[n-1];
    for (int i = 0; i < k; ++i){
        int x; cin >> x;
        int s = 0;
        if(!vis[x]){vis[x] = true; s = sum*v[x] - v[x-1]*v[x] - v[x+1]-v[x];}
        sum += s;
    }
    cout << sum << endl;
    return 0;
}

