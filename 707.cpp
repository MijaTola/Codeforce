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

char c[100][100];
int main(){
    bool flag = false;
    int n,m; cin >> n >> m;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            char x; cin >> x;
            if(x == 'C' or x == 'M' or x == 'Y') flag = true;
        }
    }
    if(!flag) cout << "#Black&White" << endl;
    else cout << "#Color" << endl;
    return 0;
}

