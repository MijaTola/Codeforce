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

vector<pair<int,int> > ans[90000];
int main(){
    int n,m,k; 
    
    cin >> n >> m >> k;
    
    int color = 0;
    int c = 0;

    bool flag = true;
    bool end = false;
    for (int i = 0; i < n; ++i){
        if(flag){
            for (int j = 0; j < m; ++j){
                if(c < 2 or end){ ans[color].push_back(make_pair(i,j)); c++;}
                else{ ans[++color].push_back(make_pair(i,j)); c = 1;}
                if(color>=k-1) end = true;
            }
            flag = false;
        }else{
            for (int j = m-1; j >= 0; --j){
                if(c < 2 or end){ ans[color].push_back(make_pair(i,j)); c++;}
                else{ ans[++color].push_back(make_pair(i,j)); c = 1;}
                if(color >= k-1) end = true;
                assert(i >= 0 and i < n and j >= 0 and j < m);
                assert(k >= 0);
            }
            flag = true;
        }
    }
    for (int i = 0; i < k; ++i){
        cout << ans[i].size() << " ";
        for (int j = 0; j < (int)ans[i].size(); ++j) cout << ans[i][j].first+1 << " " << ans[i][j].second+1 << " ";
        cout << "\n";
    }
    return 0;
}

