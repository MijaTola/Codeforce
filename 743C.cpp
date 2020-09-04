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

    if(n == 1) return cout << -1 << "\n",0;
    cout << n << " " << n*(n+1) << " " << n+1 << "\n";
    return 0;
}

