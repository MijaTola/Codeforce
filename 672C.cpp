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

long double distance(int x,int y, int a, int b){
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

vector<long double> a,b;
int main(){
    int ax,ay,bx,by,tx,ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n; cin >> n;
    long double ans = 0;
    for (int i = 0; i < n; ++i){
        int x,y; cin >> x >> y;
        ans += 2.0*distance(x,y,tx,ty);
        a.push_back(distance(ax,ay,x,y)-distance(x,y,tx,ty));
        b.push_back(distance(bx,by,x,y)-distance(x,y,tx,ty));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout.precision(12);
    long double ans2 = 1e9;
    
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
            ans2 = min(ans2,min(a[i],b[i]));
        }
    }
    cout.precision(12);
    cout << fixed << ans + ans2 << "\n";
    return 0;
}

