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

int p[110];
int v[110];

int main(){
    memset(v,0,sizeof v);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];

    sort(p,p+n);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 110; ++j){
            if(v[j] <= p[i]){v[j]++;break;}
        }
    }
    int ans = 0;
    while(v[ans] != 0) ans++;
    cout << ans << "\n";
    return 0;
}

/*
1 2 2
1 2 2
1 2 2
1 2
*/
