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

vector<pair<int,int> > a,b,c,d;
int main(){
    int n,m;
    cin >> n;
    int inin,inim,endn,endm;
    inin = inim = 0;
    endn = endm = INT_MAX;
    for (int i = 0; i < n; ++i){
        int x,y; cin >> x >> y;
        inin = max(x,inin);
        endn = min(y,endn);
    }
    cin >> m;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        inim = max(x,inim);
        endm = min(y,endm);
    }
    
    int ans1 = 0;
    int ans2 = 0;

    if(endn < inim) ans1 = abs(endn-inim);
    if(endm < inin) ans2 = abs(endm-inin);
    cout << max(ans1,ans2) << "\n";
    return 0;
}

