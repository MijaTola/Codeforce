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
    int da, db;
    
    for (int i = 1; i < 1000; ++i){
        for (int j = i+1; j < 1000; ++j){
            da = db = 0;
            for (int k = i; k <= j; ++k){
                if(k&1)db++;else da++;
                if(da == a and db == b)
                    return cout << "YES\n",0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}

