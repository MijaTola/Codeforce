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

vector<int> G[110];
int main(){
    int n; cin >> n;

    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        G[i].push_back(x);
    }
    return 0;
}

