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

set<string> v;
int main(){
    int n;
    cin >> n;
    string home; cin >> home;
    int ans  = 0;
    for (int i = 0; i < n; ++i){
        string x; cin >> x;
        string a = x.substr(0,3);
        string b = x.substr(5,8);
        if(a == home) ans++;
        if(b == home) ans--;
    }
    if(!ans) cout << "home\n";
    else cout <<"contest\n";
    
    return 0;
}

