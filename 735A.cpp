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

char v[110];
int main(){
    int n,k; cin >> n >> k;
    int a;
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        if(v[i] == 'G') a = i;
    }

    for (int i = a; a < n; i += k){
        if(v[i] != '.' and v[i] != 'G'){
            if(v[i] == 'T') return cout << "YES\n",0;
            else break;
        }
    }
    for (int i = a; a >= 0; i -= k){
        if(v[i] != '.' and v[i] != 'G'){
            if(v[i] == 'T') return cout << "YES\n",0;
            else break;
        }
    }
    cout << "NO\n";
    return 0;
}

