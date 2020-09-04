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

using namespace std;

typedef long long ll;

vector<pair<ll,int> > v;
int main(){
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int x;cin >> x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    int m; cin >> m;

    while(m--){
        ll x; cin >> x;
        int a = -1; int b = n;
        while(b-a>1){
            int mid = (a+b)>>1;
            if(v[mid].first > x) b = mid;
            else a = mid;
        }
        cout << b << endl;
    }
    return 0;
}

