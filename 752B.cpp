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

char v[28];
set<pair<int,int> > ans;
int main(){
    memset(v,-1,sizeof v);
    string x,y; cin >> x >> y;
    
    for (int i = 0; i < (int)x.size(); ++i){
        if((v[x[i]-'a'] == y[i] and v[y[i]-'a'] == x[i]) or (v[x[i]-'a'] == -1 and v[y[i]-'a'] == -1)){
            v[x[i]-'a'] = y[i];
            v[y[i]-'a'] = x[i];
        }else return cout << "-1\n",0;
    }
    
    for (int i = 0; i < 28; ++i){
        if(v[i] != -1 and v[i]-'a' != i) ans.insert({min(i,v[i]-'a'),max(i,v[i]-'a')});
    }

    cout << ans.size() << "\n";
    for (pair<int,int> v: ans)
        cout << char(v.first+'a') << " " << char(v.second+'a') << "\n";
    return 0;
}

