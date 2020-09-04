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

using namespace std;

typedef long long ll;

int main(){
    long double l,d,v,g,r;
    cin >> l >> d >> v >> g >> r;
    
    long double time1 = d/v;
    if(time1 > g){
        double temp = g;
        bool flag = true;
        while(time1 > temp or flag){
            if(flag){temp += r; flag = false;}
            else {temp += g; flag = true;}
        }
        time1 += temp - time1;
    }
    long double dist = l - d;
    long double time2 = dist/v;
    cout.precision(8);
    cout << fixed<< time1 + time2 << endl;
    return 0;
}
