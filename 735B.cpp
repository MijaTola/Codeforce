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

int v[100000];
int main(){
    int n,a,b; cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v,v+n);
    reverse(v,v+n);
    if(b < a) swap(a,b);
    
    long double ans = 0.0;
    for (int i = 0; i < a; ++i){
        ans += v[i];
    }
    ans /= a;
    
    long double ans2 = 0.0;
    for (int i = a; i < b+a; ++i){
        ans2 += v[i];
    }
    ans2 /= b;

    cout.precision(8);
    cout << fixed << ans + ans2 << "\n";
    return 0;
}

