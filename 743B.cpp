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

int main(){
    long long n;
    long long k;
    cin >> n >> k;
    long long lim = 1LL<<n;
    long long a = 0; long long b = lim;
    while(b-a>1){
        long long mid = (a+b)/2LL;
        if(mid == k) return cout << n << "\n",0;
        if(k > mid) a = mid;
        else b = mid;
        n--;
    }
    return 0;
}

