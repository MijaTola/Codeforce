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

using namespace std;

typedef long long ll;

int main(){
    double a,b; cin >> a >> b;
    int n; cin >> n;
    double ans = 1e9;
    while(n--){
        double x,y,v; cin >> x >> y >> v;
        double dis = sqrt((x-a)*(x-a)+(y-b)*(y-b));
        double t = dis/v;
        ans = min(ans,t);
    }
    cout.precision(20);
    cout << fixed << ans << "\n";
    return 0;
}

