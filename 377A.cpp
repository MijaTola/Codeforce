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

char c[510][510];
bool vis[510][510];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m,k;
int r = 0;

void dfs(int x, int y){
    if(!r) return;
    if(x < 0 or x > n or y < 0 or y > m or c[x][y] != '.' or vis[x][y]) return;
    r--;
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i){
        int u = dx[i] + x;
        int v = dy[i] + y;
        dfs(u,v);
    }
}
int main(){
    memset(vis,false,sizeof vis);
    cin >> n >> m >> k;
    r = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            cin >> c[i][j];
            if(c[i][j] == '.') r++;
        }
    r -= k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dfs(i,j);
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(!vis[i][j] and c[i][j] == '.') cout << "X";
            else cout << c[i][j];
        }
        cout << "\n";
    }

    return 0;
}

