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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < 1e4; ++i)
        for (int j = 0; j < 1e4; ++j)
            if((long long)b+a*i == (long long)d+c*j) return cout << b+a*i << "\n",0;
    
    cout << "-1\n";
    return 0;
}

