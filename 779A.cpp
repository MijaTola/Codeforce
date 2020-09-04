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

int a[6],b[6];
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        b[x]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= 5; ++i){
        int p = a[i]+b[i];
        if(p&1) return cout << "-1\n",0;
        p /=2 ;
        ans += abs(a[i]-p)+abs(b[i]-p);
    }
    cout << ans/4<< "\n";
    return 0;
}

