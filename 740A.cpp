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

long long n,a,b,c,dif,limit;

long long f(int u){
    if(u%4==0) return 0;
    if(u > limit) return 1e15;
    long long ans = LLONG_MAX;
    ans = min(ans,f(u+1)+a);
    ans = min(ans,f(u+2)+b);
    ans = min(ans,f(u+3)+c);
    return ans;
}
int main(){
    cin >> n >> a >> b >> c;
    for (int i = n; i <= n+12; ++i) if(i%4==0) limit = i;
    cout << f(n) << "\n";
    return 0;
}

