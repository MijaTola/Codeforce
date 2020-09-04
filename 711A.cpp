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

char c[1010][5];
int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 5; ++j) cin >> c[i][j];
    }
    
    bool ans = false;
    int idy;
    int idx;
    for (int i = 0; i < n; ++i){
        if(c[i][0] == 'O' and c[i][1] == 'O'){
            ans = true;
            idy = i;
            idx = 0;
            break;
        }
        if(c[i][3] == 'O' and c[i][4] == 'O'){
            ans = true;
            idy = i;
            idx = 3;
            break;
        }
    }
    if(ans) cout << "YES" << endl;
    else return cout << "NO" << endl,0;

    c[idy][idx] = '+';
    c[idy][idx+1] = '+';
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 5; ++j){
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}

