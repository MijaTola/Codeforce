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

int v[20];
int total[20];
int n,l,r,x;
int f(int pos, int first, int last, int sum){
    if(pos == n){
        if(sum >= l and sum <= r and v[last]-v[first] >= x and first != -1 and last != -1) return 1;
        return 0;
    }
    int ans = 0;
    if(first == -1) ans += f(pos+1,pos,last,sum+v[pos]);
    else ans += f(pos+1,first,pos,sum+v[pos]);
    ans += f(pos+1,first,last,sum);
    return ans;
}
int main(){
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v,v+n);
    cout << f(0,-1,-1,0) << "\n";
    return 0;
}

