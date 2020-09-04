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

int main(){
    int n,a,b; cin >> n >> a >> b;
    string x; cin >> x;
    a--,b--;
    if(b < a) swap(a,b);
    int ans = 0;
    while(x[a] != x[b]){
        a++;
        if(x[a] != x[a-1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}

