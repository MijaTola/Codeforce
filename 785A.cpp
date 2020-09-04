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
    int ans = 0;
    while(n--){
        string x; cin >> x;
        if(x == "Tetrahedron") ans += 4;
        if(x == "Cube") ans += 6;
        if(x == "Octahedron") ans += 8;
        if(x == "Dodecahedron") ans += 12;
        if(x == "Icosahedron") ans += 20;
    }
    cout << ans << "\n";
    return 0;
}

