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

string x,y;

bool ver(string u){
    string z = u;
    reverse(u.begin(),u.end());
    return z == u;
}
int main(){

    cin >> x >> y;
    for (int i = 0; i < (int)x.size(); ++i){
        y = x;
        char cur = x[i];
        for (char j = 'a'; j <= 'z'; ++j){
            if(cur == j) continue;
            y[i] = j;
            if(ver(y)) return puts("YES");
        }
    }
    puts("NO");
    return 0;
}

