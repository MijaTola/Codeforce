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
    
    int n,m,k; cin >> n >> m >> k;
    
    int pos = 1;
    while(2*m*pos < k and pos < n){pos++;}
    int ans2 = 1;
    for (int pos2 = 2*m*(pos-1)+1; pos2 <= k; pos2+=2,ans2++);
    cout << pos << " " << ans2-1 << " ";
    if(k&1) cout << "L\n";
    else cout << "R\n";
    return 0;
}

