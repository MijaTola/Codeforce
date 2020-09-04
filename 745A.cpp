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

set<string> s;
int main(){
    string x; cin >> x;
    int n = x.size();
    for (int i = 0; i < n; ++i){
        string p = "";
        for (int j = i; j < n; ++j) p += x[j];
        for (int j = 0; j < i; ++j) p += x[j];
        s.insert(p);
    }
    cout << s.size() << "\n";
    return 0;
}

