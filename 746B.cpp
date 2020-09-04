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
    string x; cin >> x;
    
    string ans = "";
    bool flag;
    if((int)x.size()%2 == 0) flag = false;
    else flag = true;

    // r and l
    for (int i = 0; i < (int)x.size(); ++i){
        if(flag){ ans = ans + x[i]; flag = false;}
        else{ans = x[i] + ans; flag = true;}
    }
    cout << ans << "\n";
    return 0;
}

