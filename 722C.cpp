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

ll st[2*100010];
int n;
void update(int pos, ll value){
    for (st[pos+=n] = value; pos > 1; pos>>=1)
        st[pos>>1] = st[pos]+st[pos^1];
}

ll query(int l,int r){
    ll ans = 0LL;
    r++;
    for (l+=n,r+=n;l<r;r>>=1,l>>=1){
        if(l&1) ans+=st[l++];
        if(r&1) ans+=st[--r];
    }
    return ans;
}
set<int> s;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i){
        ll x; cin >> x;
        update(i,x);
    }
    s.insert(n);
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        int last = -1;
        x--;
        s.insert(x);
        ll mx = -1;
        for (int v: s){
            mx = max(mx,query(last+1,v-1));
            last = v;
        }
        cout << mx << "\n";

    }
    return 0;
}

