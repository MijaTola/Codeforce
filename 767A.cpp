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
vector<int> ans[100010];
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v,v+n); reverse(v,v+n);
    int pos = -1;
    for (int i = 0; i < n; ++i){
        int p1 = v[i].second;
        if(p1 > pos or pos ==-1){
            ans[p1].push_back(v[i].first);
            pos = p1;;
        }else ans[pos].push_back(v[i].first);
    }
    
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j < (int)ans[i].size(); ++j)
            cout <<ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

