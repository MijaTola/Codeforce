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

typedef long long ll;
vector<ll> v;
set<ll>  s;
int main(){
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        ll x; cin >> x;
        s.insert(x);
    }
    if(s.size() == 1) return cout << "YES" << endl,0;
    if(s.size() > 3) return cout << "NO" << endl,0;
    for (int i: s) v.push_back(i);
    s.clear();
    for (int i = 1; i < (int)v.size(); ++i)
        s.insert(v[i]-v[i-1]);
    if(s.size() == 1) return cout << "YES" << endl,0;
    else cout << "NO" << endl;
    return 0;
}

