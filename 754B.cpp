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

char m[4][4];
vector<pair<int,int> > v;

bool ver1(int x,int y){
    if(x+1<4 and y+1<4 and x-1>= 0 and y-1>= 0 and m[x+1][y+1] == 'x' and m[x-1][y-1] == 'x')  return true;
    if(y+1<4 and y-1>=0 and m[x][y+1] == 'x' and m[x][y-1] == 'x') return true;
    if(x+1<4 and x-1>=0 and m[x+1][y] == 'x' and m[x-1][y] == 'x') return true;
    if(x-1>= 0 and x+1<4 and y-1>=0 and y+1<4 and m[x-1][y+1] == 'x' and m[x+1][y-1] == 'x') return true;
    return false;
}

bool ver2(int x, int y){
    if(x+1 < 4 and y+1 < 4 and x+2 < 4 and y+2 < 4 and m[x+1][y+1] == 'x' and m[x+2][y+2] == 'x') return true;
    if(x+1 < 4 and x+2 < 4 and m[x+1][y] == 'x' and m[x+2][y] == 'x') return true;
    if(x+1 < 4 and x+2 < 4 and y-1 >= 0 and y-2>=0 and m[x+1][y-1] == 'x' and m[x+2][y-2] == 'x') return true;
    if(y-1 >= 0 and y-2 >= 0 and m[x][y-1] == 'x' and m[x][y-2] == 'x') return true;
    if(x-1 >= 0 and x-2 >= 0 and y-2 >= 0 and y-1 >= 0 and m[x-1][y-1] == 'x' and m[x-2][y-2] == 'x') return true;
    if(x-1 >= 0 and x-2 >= 0 and y+1<4 and y+2 <4 and m[x-1][y+1] == 'x' and m[x-2][y+2] == 'x') return true;
    if(x-1 >= 0 and x-2 >= 0 and m[x-1][y] == 'x' and m[x-2][y] == 'x') return true;
    if(y+1<4 and y+2<4 and m[x][y+1] == 'x' and m[x][y+2] == 'x') return true;
    return 0;
}
int main(){
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j){
            cin >> m[i][j];
            if(m[i][j] =='.') v.push_back({i,j});
        }

    for (int i = 0; i < (int)v.size(); ++i){
        int x = v[i].first;
        int y = v[i].second;
        if(ver1(x,y)) return cout << "YES\n",0;
        if(ver2(x,y)) return cout << "YES\n",0;
    }
    cout << "NO\n";
    return 0;
}

