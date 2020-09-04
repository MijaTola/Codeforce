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

int servers[110];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,q; cin >> n >> q;
    while(q--){
        int t,k,d;
        cin >> t >> k >> d;
        int ans = 0;
        vector<int> pos;
        for (int i = 0; i < n and k; ++i){
            if(servers[i] <= t){
                pos.push_back(i);
                k--;
                ans += i+1;
            }
        }
        if(k){ cout << -1 <<"\n"; continue;}
        for (int i = 0; i < (int)pos.size(); ++i)
            servers[pos[i]] = t+d;

        cout << ans << "\n";
    }
    return 0;
}

