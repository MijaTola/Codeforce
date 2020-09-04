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

int p,x,y;
bool vis[10000000];
bool find(int s){
    int i = (s / 50) % 475;
    for (int j = 0; j < 25; ++j){
        i = (i * 96 + 42) % 475;
        if(i+26 == p) return true;
    }
    return false;
}
queue<pair<int,int> > q;
int main(){
    memset(vis,false,sizeof vis);
    scanf("%d %d %d",&p,&x,&y);
    q.push(make_pair(x,0));

    int ans = 1e9;
    while(!q.empty()){
        int u = q.front().first; 
        int c = q.front().second; 
        q.pop();
        if(u < y or u > 10000000 or vis[u]) continue;
        vis[u] = true;
        if(find(u)) ans = min(ans,c);// return printf("%d\n",c),0;
        q.push(make_pair(u+100,c+1));
        q.push(make_pair(u-50,c));
    }
    printf("%d\n",ans);
    return 0;
}

