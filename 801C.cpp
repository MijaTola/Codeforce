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

long double da[100010];
long double db[100010];
int n,p;
bool ver(long double cur){
    long double sum = 0;
    for (int i = 0; i < n; ++i){
        long double t = db[i] / da[i];
        sum += max(0.0L,(long double)(cur-t)*da[i]);
    }
    return (long double)p*cur >= sum;
}
int main(){
    cin >> n >> p;
    long double sum = 0;
    for (int i = 0; i < n; ++i){
        cin >> da[i] >> db[i];
        sum += da[i];
    }
    if(p >= sum) return cout << "-1\n",0;
    
    long double a = 0;
    long double b = 1e18;

    for (int i = 1; i < 220; ++i){
        long double mid = (a+b)/2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    cout.precision(10);
    cout << fixed << b << "\n";
    return 0;
}

