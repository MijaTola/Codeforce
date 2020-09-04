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
    string x; cin >> x;
    int pos = 0;
    int ans = 0;
    for (int i = 0; i < (int)x.size(); ++i){
        int p = x[i]-'a';
        ans += min(abs(pos-p),26-abs(pos-p));
        pos = x[i]- 'a';
    }
    cout << ans << endl;
    return 0;
}

