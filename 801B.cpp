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
    string x,y;
    cin >> x >> y;
    //f(x,z) = y
    string z = "";
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] <= y[i]) z += x[i];
        else z += y[i];
    }
    string a = "";

    for (int i = 0; i < (int)x.size(); ++i){
         a += min(x[i],z[i]);
    }
    if(a != y) cout << "-1\n";
    else cout << z << "\n";
    return 0;
}

