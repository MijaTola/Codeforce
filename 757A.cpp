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

map<char,int> m;

bool ver(char x){
    if(x == 'B' or x == 'u' or x == 'l' or x == 'a' or x=='r' or x == 'b' or x == 's')
        return true;
    return false;
}
int main(){
    m['B'] = 0;
    m['u'] = 0;
    m['b'] = 0;
    m['a'] = 0;
    m['s'] = 0;
    m['r'] = 0;
    m['l'] = 0;
    string x; cin >> x;
    for (int i = 0; i < (int)x.size(); ++i)
        if(ver(x[i])) m[x[i]]++;
    
    m['u'] /= 2;
    m['a'] /= 2;
    int ans = 1e9;
    for (pair<char,int> v: m)
        ans = min(ans,v.second);
    cout << ans << "\n";
    return 0;
}

