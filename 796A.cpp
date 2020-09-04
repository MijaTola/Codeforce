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
    
    int n,m,k;

    cin >> n >> m >> k;
    int distance = 1e9;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        if(i == m or x == 0) continue;
        if(abs(m-i) < distance and x <= k)
            distance = abs(m-i);
    }
    cout << distance*10<< "\n";
    return 0;
}

