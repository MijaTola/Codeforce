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
    
    string x; cin >> x;
    
    int ans = -1;
    int last = -1;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == 'A' or x[i] == 'E' or x[i] == 'I'  or x[i] == 'O' or x[i] == 'U' or x[i] == 'Y') {
            int dif = i - last;
            last = i;
            ans = max(ans,dif);
        }
    }
    ans = max(ans, (int)x.size() - last);
    cout << ans << "\n";
    return 0;
}

