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

int a[110];
int b[110];
bool v[110];
bool vx[110];
int main(){
    memset(v,false,sizeof v);
    int n,l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i < l; ++i){
        for (int j = 0; j < l; ++j){
            memset(vx,false,sizeof vx);
            memset(v,false,sizeof vx);
            for (int k = 0; k < n; ++k){
                v[(i+a[k])%l] = true;
                vx[(j+b[k])%l] = true;
            }
            int c = 0;
            for (int k = 0; k < l; ++k)
                if(v[k] and vx[k])c++;
            if(c == n) return cout << "YES\n",0;
        }
    }
    cout << "NO\n";
    return 0;
}

