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

int v[100010];
set<int> s;
map<int,int> dd;
vector<pair<int,int> > p;
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> v[i];
        s.insert(v[i]);
    }
    if(n == 1) return cout << "-1\n",0;
    if((int)s.size() == 1) return cout << "1\n" << v[0],0;
    sort(v,v+n);
    
    for (int i = 1; i < n; ++i){
        int d = v[i]-v[i-1];
        dd[d]++;
    }
    for (pair<int,int> v: dd)
        p.push_back(make_pair(v.first,v.second));
    
    if((int)dd.size() == 1){
        if(n == 2 and (v[0]+v[1])%2 == 0) return cout << "3\n" << v[0]-p[0].first <<" " << (v[0]+v[1])/2 << " " << v[n-1]+p[0].first,0;
        return cout << 2 <<"\n" << v[0]-p[0].first << " " << v[n-1]+p[0].first,0;
    }
    if((int)dd.size() == 2 and p[1].first >= 1 and p[1].second <= 1){
        for (int i = 1; i < n; ++i)
            if(v[i]-v[i-1] == p[1].first and (v[i-1]+p[0].first == v[i]-p[0].first)) return cout << "1\n" <<v[i]-p[0].first,0;
    }
    
    cout << "0\n";
    return 0;
}

