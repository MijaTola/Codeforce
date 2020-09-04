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

int v[100010],n;

int main(){
    scanf("%d",&n);
    
    int gcd = 0;
    for (int i = 0; i < n; ++i){
        scanf("%d",v+i);
        gcd = __gcd(gcd,v[i]);
    }
    if(gcd > 1) return puts("YES\n0"),0;
    int ans = 0;
    for (int i = 1; i < n; ++i){
        if(v[i-1] & 1){
            if(v[i] & 1) ans ++;
            else ans += 2;
            v[i] = 0;
        }
    }
    if(v[n-1] & 1) ans += 2;
    printf("YES\n%d\n",ans);
    return 0;
}

