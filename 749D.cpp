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

set<pair<int,int> > s;
vector<int> v[200010];
int b[200010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int x,y; cin >> x >> y;
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i)
        if(v[i].size() > 0)
            s.insert({v[i].back(),i});
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        for (int i = 0; i < k; ++i){
            cin >> b[i];
            if(v[b[i]].size())s.erase({v[b[i]].back(),b[i]});
        }
        if(s.size() == 0) cout << "0 0\n";
        else if(s.size() == 1) cout << s.begin()->second << " " << v[s.begin()->second][0] << "\n";
        else{
            set<pair<int,int> >:: reverse_iterator a,b;
            a = s.rbegin();
            b = s.rbegin();
            b++;
            int mx = v[b->second].back();
            int pos = a->second;
            int ans = v[pos][lower_bound(v[pos].begin(),v[pos].end(),mx)-v[pos].begin()];
            cout << pos << " " << ans << "\n";
        }
        for (int i = 0; i < k; ++i)
            if(v[b[i]].size())s.insert({v[b[i]].back(),b[i]});
    }
    return 0;
}

