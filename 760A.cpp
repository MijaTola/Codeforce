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

int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int m,d;
    
    cin >> m >> d;
    int total = month[m];
    int ans = 1; 
    bool first = true;
    for (int i = d; i < total+d; ++i){
        if(i%7==1 and !first){ ans++;}
        first = false;
    }
    cout << ans << "\n";
    return 0;
}

