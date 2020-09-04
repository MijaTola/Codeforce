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

set<pair<int,string> > s;
int v[110];

int main(){
    int n,k; cin >> n >> k;
    for (int i = 0; i < n; ++i){
        string x; cin >> x;
        v[x.size()]++;
    }
    string p; cin >> p;
    int sz = p.size();
    int mn = 0;
    int mx = 0;
    for (int i = 1; i < 110; ++i){
        if(i < sz) mn += v[i];
        if(i <= sz) mx += v[i];
    }
    mn++;
    cout << floor((mn-1)/k)*5+mn << " " << floor((mx-1)/k)*5+mx << endl;
    return 0;
}

