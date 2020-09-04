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

int n;
ll m[510][510];
int main(){
    cin >> n;
    
    ll x,y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            cin >> m[i][j];
            if(m[i][j] == 0){
                x = i; y = j;}
        }
    if(n == 1){
        if(m[0][0] != 0) return cout << m[0][0] << endl,0;
        else return cout << 1 << endl,0;
    }
    ll total = 0;
    bool first = true;
    bool exist = true;
    for (int i = 0; i < n; ++i){
        ll sum = 0;
        if(i == x) continue;
        for (int j = 0; j < n; ++j)
            sum += m[i][j];
        if(first){total = sum;first = false;}
        if(total != sum){exist = false; break;}
    }
    for (int i = 0; i < n; ++i){
        ll sum = 0; if(i == y) continue;
        for (int j = 0; j < n; ++j)
            sum += m[j][i];
        if(total!=sum){exist = false;break;}
    }
    ll sum = 0;
    bool zero = false;
    for (int i = 0; i < n;++i){
        sum += m[i][i];
        if(m[i][i] == 0) zero = true;
    }
    if(!zero) if(sum != total) exist = false;
    sum = 0;
    zero = false;
    for (int i = 0; i < n; ++i){
        sum += m[i][n-1-i];
        if(m[i][n-1-i] == 0) zero = true;
    }

    if(!zero and sum != total) exist = false;
    sum = 0;
    if(!exist) return cout << -1 << endl,0;
    for (int i = 0;i < n;  ++i)sum += m[x][i];
    cout << total - sum << endl;
    return 0;
}

