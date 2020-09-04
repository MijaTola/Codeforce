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

bool vis[28];
int main(){
    memset(vis,false,sizeof vis);
    string x; cin >> x;
    int cur = 0;

    for (int i = 0; i < (int)x.size(); ++i){
        if(!vis[x[i]-'a']){
            if(x[i] != char(cur+'a')) return cout << "NO\n",0;
            vis[x[i]-'a'] = true;
            cur++;
        }
    }
    cout << "YES\n";
    return 0;
}

