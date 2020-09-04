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

set<long long> s;
queue<long long> q;
vector<long long> v;
int main(){
    
    q.push(4);
    q.push(7);

    while(!q.empty()){
        ll u = q.front();
        q.pop();
        if(s.count(u) or u > 1e10) continue;
        s.insert(u);
        v.push_back(u);
        q.push(u*10+4);
        q.push(u*10+7);
    }

    sort(v.begin(),v.end());

    long long  l,r;
    cin >> l >> r;
    long long ans = 0;
    int p1 = lower_bound(v.begin(),v.end(),l) - v.begin();
    int p2 = lower_bound(v.begin(),v.end(),r) - v.begin();
    
    for (int i = p1+1; i <= p2; ++i)
        ans += v[i]*(v[i]-v[i-1]);

    ans += v[p1]*(v[p1]-l+1LL);
    ans -= v[p2]*(v[p2]-(long long)r);
    cout << ans << "\n";
    return 0;
}

