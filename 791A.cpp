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
    int a,b;
    cin >> a >> b;
    int ans = 0;

    while(a <= b){
        a *= 3;
        b *= 2;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}

