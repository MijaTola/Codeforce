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
    
    int x,y; cin >> x >> y;

    int a,b,c;
    a = b = c = y;
    int ans = 0;
    while(a < x or b < x or c < x){
        if(ans%3 == 1) a = c+b-1;
        if(ans%3 == 2) b = a+c-1;
        if(ans%3 == 0) c = a+b-1;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}

