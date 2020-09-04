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

using namespace std;

typedef long long ll;

int main(){
    int n; cin >> n;
    int s = 0;

    for (int i = 0;i  < n; ++i){
        int x; cin >> x;
        s +=x;
    }
    if(n == 1){
        if(s == 1) return cout << "YES" << endl,0;
        else return cout << "NO" << endl,0;
    }
    if(s == n-1) return cout << "YES"<< endl,0;
    else cout <<"NO"<< endl;
    return 0;
}

