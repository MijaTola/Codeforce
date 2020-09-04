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
    int i;
    for (i = 0; i < (int)x.size(); ++i)
        if(x[i] == '|') break;
    
    string y; cin >> y;
    int a = i;
    int b = x.size()-i-1;
    
    if(a+(int)y.size() == b) cout << y << x.substr(0,i) << "|" << x.substr(i+1,x.size()-1);
    else if(b+(int)y.size() == a) cout <<x.substr(0,i) << "|"<<y << x.substr(i+1,x.size()-1);
    else cout << "Impossible";
    return 0;
}

