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

int main(){
    
    ll v[3];

    cin >> v[0] >> v[1] >> v[2];

    sort(v,v+3);

    cout << min((v[1]+v[0]+v[2])/3,v[0]+v[1]) << endl; 
    return 0;
}
