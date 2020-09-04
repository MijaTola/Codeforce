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

priority_queue<pair<int,char> > q;
set<int> ver;
vector<int> pos;
int main(){
    int n; cin >> n;
    string x; cin >> x;
    
    int a,c,g,t;
    a = c = g = t = 0;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == 'A') a++;
        if(x[i] == 'C') c++;
        if(x[i] == 'G') g++;
        if(x[i] == 'T') t++;
        if(x[i] == '?') pos.push_back(i);
    }
    
    int total = a+c+g+t;
    q.push({-a,'a'});
    q.push({-c,'c'});
    q.push({-g,'g'});
    q.push({-t,'t'});
    int da = 0;
    int dc = 0;
    int dg = 0;
    int dt = 0;
    for (int i = 0; i < n-total; ++i){
        int p = -q.top().first;
        char t = q.top().second; q.pop();
        if(t == 'a') da++;
        if(t == 'c') dc++;
        if(t == 'g') dg++;
        if(t == 't') dt++;
        q.push({-(p+1),t});
    }
    while(!q.empty()){
        int p = -q.top().first;
        q.pop();
        ver.insert(p);
    }
    if(ver.size() > 1) return cout << "===\n",0;
    for (int i = 0; i < (int)pos.size(); ++i){
        if(da){x[pos[i]] = 'A'; da--; continue;}
        else if(dc){x[pos[i]] = 'C'; dc--; continue;}
        else if(dg){x[pos[i]] = 'G'; dg--; continue;}
        else if(dt){x[pos[i]] = 'T'; dt--; continue;}
    }
    cout << x << "\n";
    return 0;
}

