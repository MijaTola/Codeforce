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
int n,a;
vector<int> v;
set<int> troll;
int main(){
    cin >> n >> a;
    for (int i = 0; i < n; ++i){
        int x;cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int dis = min(abs(v[0]- a),abs(v[v.size()-1]-a));
    ll ans1 = abs(v[v.size()-1] - v[1])+dis;
    ll ans2 = abs(v[v.size()-2] -v[0])+dis;
    cout << min(ans1,ans2) << endl;
    return 0;
}

	
