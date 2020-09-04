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

queue<int> d;
queue<int> r;
bool denied[200000];
int main(){
    memset(denied,false,sizeof denied);
    int n; cin >> n;
    string x; cin >> x;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == 'D') d.push(i);
        if(x[i] == 'R') r.push(i);
    }
    while(!d.empty() and !r.empty()){
        int p1 = d.front(); d.pop();
        int p2 = r.front(); r.pop();
        if(p1 < p2) d.push(p1+n);
        else r.push(p2+n);
    }
    if(d.empty()) cout << "R\n";
    else cout << "D\n";
    return 0;
}

