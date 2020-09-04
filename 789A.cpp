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

int v[100010];
int main(){
    
    int n,k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v,v+n);
    
    int d = 0;
    for (int i = 0; i < n; ++i)
        d += (v[i]+k-1)/k;

    cout << (d +1)/2 << "\n";
    return 0;
}

