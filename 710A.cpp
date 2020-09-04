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

using namespace std;

typedef long long ll;

int main(){
    char c;int d;
    cin >> c >> d;
    bool f1 = false;
    bool f2 = false;
    if(c == 'a' or c == 'h') f1 = true;
    if(d == 1 or d == 8) f2 = true;
    if(f1 and f2) cout << 3 << endl;
    else if(f1 or f2) cout << 5 << endl;
    else cout << 8 << endl;
    return 0;
}

