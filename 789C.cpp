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
int a[100010];
int main(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    
    for (int i = 1; i < n; ++i) a[i] = abs(v[i]-v[i+1]);
    
    long long ans = LLONG_MIN;
    long long sum = 0LL;
    int sign = 1;
    for (int i = 1; i <= n; ++i){
        sum += a[i]*sign;
        sum = max(sum,0LL);
        ans = max(ans,sum);
        sign*=-1;
    }
    sign = -1;
    sum = 0;
    for (int i = 1; i <= n; ++i){
        sum += a[i]*sign;
        sum = max(sum,0LL);
        ans = max(ans,sum);
        sign*=-1;
    }
    cout << ans << "\n";
    return 0;
}

