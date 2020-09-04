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
    int n; cin >> n;
    int s = 0;
    while(n--){
        int t; string x;
        cin >> t >> x;
        if(s == 0 and x != "South") return cout << "NO\n",0;
        if(s == 20000 and  x!= "North") return cout << "NO\n",0;
        if(x == "South") s += t;
        if(x == "North") s-= t;
        if(s > 20000 or s < 0) return cout << "NO\n",0;
    }
    if(s != 0) return cout << "NO\n",0;
    cout << "YES\n";
    return 0;
}

