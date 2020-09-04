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

vector<int> v;

int main(){
    
    int n,k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i)
        v.push_back(i);

    int cur = 0;
    while(k--){
        int x; cin >> x;
        int pos = x%(int)v.size();
        pos = (cur+pos)%(int)v.size();
        cur = pos;
        cout << v[pos] << " ";
        v.erase(v.begin()+pos);
    }
    return 0;
}

