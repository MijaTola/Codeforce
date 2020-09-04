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

int power(int x, unsigned int y, int p){
    int res = 1;   
    x = x % p;  
    while (y > 0){
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    cout << power(1378,n,10) << "\n";
    return 0;
}

