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

bool cups[1000010];
bool holes[1000010];
int main(){
    memset(cups,false,sizeof cups);
    memset(holes,false,sizeof holes);
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    
    for (int i = 0; i < m; ++i){
        int x; scanf("%d",&x);
        holes[x] = true;
    }
    bool done = false;
    cups[1] = 1;
    int ans = 1;
    if(holes[1]){ans = 1,done = true;}
    for (int i = 0; i < k; ++i){
        int u,v; scanf("%d %d",&u,&v);
        if(!done){
            swap(cups[u],cups[v]);
            if(cups[v]) ans = v;
            if(holes[v] and cups[v]) done = true;
            if(cups[u]) ans = u;
            if(holes[u] and cups[u]) done = true;
        }
    }
    printf("%d\n",ans);
    return 0;
}

