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

const double eps = 1e-6;
ll v[34];
int bs(int x){
    int a = -1; int b = 34;
    while(b-a > 1){
        int mid = (a+b)>>1;
        if(v[mid] > x) b = mid;
        else a = mid;
    }
    return v[a];
}
int main(){
    for (ll i = 0; i < 34; ++i)
        v[i] = (long long) 1<<i;
    //for (int i = 0; i < 34; ++i) cout << v[i] << endl;
    ll a,b; cin >> a >> b;
    ll da = bs(a);
    ll db = bs(b);
    int ans1 = -1;
    for (int i = 1; i <= b; ++i){
        double r = (double)da/i;
    //    cout << i << " " << da << " " << r <<  endl; 
        if(r >= 0.8+eps and r <= 1.25+eps)
            ans1 = i;
    }
    //cout << da << " " << ans1 << endl;
    int ans2 = -1;
    for (int i = 1; i <= a; ++i){
        double r = (double) db/i;
        if(r >= 0.8+eps and r <= 1.25+eps) ans2 = i;
    }
    //cout << ans2 << " " << db << endl;
    if(da*ans1 > db*ans2) cout <<da << " " << ans1 << endl;
    else  cout << ans2 << " " << db << endl;
    return 0;
}

