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

int v[100010];
int n;
int f(int pos, int gcd){
    if(pos == n){
        cout << gcd << "\n";
        if(gcd > 0) return 0;
        return 1e9;
    }
    int ans = 0;
    ans = max(ans,f(pos+1,__gcd(gcd,v[pos]))+1);
    ans = max(ans,f(pos+1,gcd));
    return ans;
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, f(i,v[i]));
    cout << ans << "\n";
    return 0;
}

