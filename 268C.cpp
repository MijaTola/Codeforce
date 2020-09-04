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

vector<pair<int,int> > ans;

int main(){
    int n,m; cin >> n >> m;
    
    cout << min(m,n) +1 << endl;
    
    int x = 0;
    int y = m;
    while(x <= n and y >= 0){
        cout << x << " " << y << endl;
        x++,y--;
    }
    return 0;
}

