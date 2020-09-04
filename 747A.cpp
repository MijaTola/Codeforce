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
    
    int dif = 1e9;
    int a = -1;
    int b = -1;
    for (int i = 1; i <= n; ++i){
        if(n%i == 0){
            int p = n/i;
            if(abs(p-i) < dif){
                a = min(p,i);
                b = max(p,i);
                dif = abs(p-i);
            }
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}

