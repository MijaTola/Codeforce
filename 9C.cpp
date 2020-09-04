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

int main(){
    
    int n; cin >> n;
    
    queue<int> q;
    
    q.push(1);
    int ans = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u > n) continue;
        ans++;
        q.push(u*10+1);
        q.push(u*10+0);
    }
    cout << ans << "\n";
    return 0;
}

