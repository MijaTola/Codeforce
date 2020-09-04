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

vector<string> lvl[1000010];
vector<string> v;
stack<pair<int,int> > s;
string x;
int convert(string q){
    istringstream ss(q);
    int y;
    ss >> y;
    return y;
}

int main(){
    
    cin >> x;
    string cur = "";
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == ','){
            v.push_back(cur);
            cur = "";
        }else cur += x[i];
    }
    v.push_back(cur);
    int ans = -1;
    s.push({1,1e9});
    for (int i = 0; i < (int)v.size(); i += 2){
        int curlvl = s.top().first;
        int needed = s.top().second;
        int cur = convert(v[i+1]);
        s.pop();
        ans = max(curlvl,ans);
        lvl[curlvl].push_back(v[i]);
        needed--;
        if(needed > 0) s.push({curlvl,needed});
        if(cur > 0) s.push({curlvl+1,cur});
    }
    cout << ans << "\n";
    for (int i = 1; i <= ans; ++i){
        for (string v: lvl[i]) cout << v << " ";
        cout << "\n";
    }
    return 0;
}

