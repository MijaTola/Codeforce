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

typedef long long ll;

int main(){
    int n; cin >> n;
    string x; cin >> x;
    if(n == 24){
        if(x[0] >= '2' and x[1] > '3'){x[0] = '0';}
        else if(x[0] > '2'){x[0] = '1';}

    }else{
        if(x[0] > '1' and x[1] > '0') x[0] = '0';
        else if(x[0] > '1') x[0] = '1'; 
        else if(x[0] >= '1' and x[1] > '2') x[0] = '0';
        if(x[0] == '0' and x[1] == '0') x[1] = '1';
    }

    if(x[3] > '5') x[3] = '0';
    cout << x << endl;
    return 0;
}
