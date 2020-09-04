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

pair<int,int> v[100010];
int main(){
    
    int n; cin >> n;
    int tr = 0;
    int tl = 0;
    for (int i = 0; i < n; ++i){
        cin >> v[i].first >> v[i].second;
        tr += v[i].second;
        tl += v[i].first;
    }
    
    int ans = abs(tr-tl);
    int id = -1;
    for (int i = 0; i < n; ++i){
        int curtr = tr + v[i].first - v[i].second;
        int curtl = tl + v[i].second - v[i].first;
        int curans = abs(curtr - curtl);
        if(curans > ans){
            ans = curans;
            id = i;
        }
    }
    cout << id+1 << "\n";
    return 0;
}

