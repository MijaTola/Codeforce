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

long long x,y,p,q;
bool ver(long long moves){
    if(p*moves >= x and q*moves >= y and q*moves-y+x >= p*moves) return true;
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld %lld",&x,&y,&p,&q);
        long long a = 0LL;
        long long b = 1000000000LL;
        
        if(p == 0){
            if(x > 0) puts("-1");
            else puts("0");
            continue;
        }
        
        if(p == q){
            if(x < y) puts("-1");
            else puts("0");
            continue;
        }
        while(b-a>1){
            long long mid = (a+b)>>1;
            if(ver(mid)) b = mid;
            else a = mid;
        }

        printf("%lld\n",abs(y-q*b));
    }
    return 0;
}

