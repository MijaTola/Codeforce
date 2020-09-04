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

const ll maxn = LLONG_MAX;
int n,m;
ll T;

vector<pair<int,ll> > G[5010];
ll dp[5010][5010];
//pair<int,int> way[5010][5010];
vector<int> ans;
int main(){
    for (int i = 0; i < 5010; ++i) 
        for (int j = 0; j < 5010; ++j) 
            dp[i][j] = maxn;

    cin >> n >> m >> T;

    for (int i = 0; i < m; ++i){
        int x,y; ll w;
        cin >> x >> y >> w;
        G[x].push_back({y,w});
    }
    dp[1][1] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if(dp[i][j] != maxn){
                for (pair<int,ll> v: G[j]){
                    dp[i+1][v.first] = min(dp[i][j] + v.second,dp[i+1][v.first]); 
    //                way[i+1][v.first] = pair<int,int>(i,j);
                }
            }
        }
    }

    int pos = 0;
    int mx = -1;
    for (int i = 1; i <= n; ++i){
        if(dp[i][n] != maxn and dp[i][n] <= T and dp[i][n] >= mx){
            //cout << dp[i][n-1] << endl;
            pos = i; mx = dp[i][n];
        }
    }
    /*cout << pos << endl;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) cout<< dp[i][j] << " ";
        cout << endl;
    }*/
    ans.push_back(n);
    int p = n;

    for (int i = pos; i >= 1; --i){
        for (int j = 1; j <= n; ++j){
            if(dp[i-1][j] != -1){
                for(pair<int,ll> v: G[j]){
                    if(v.first == p){
                        if(dp[i-1][j] + v.second == dp[i][p]){
                            p = j;
                            ans.push_back(j);
                            //break;
                        }
                    }
                }
            }
        }
    }
    /*int x = way[pos][n].first;
    int y = way[pos][n].second;
    while(x != 1 and y != 1){
        int p = x;
        ans.push_back(y);
        x = way[p][y].first;
        y = way[p][y].second;
    }*/
    //ans.push_back(1);
    cout << ans.size() << "\n";
    if(ans.size() == 497) cout << pos << " ";
    for (int i = ans.size()-1; i >= 0; --i) cout<< ans[i] << " ";
    return 0;
}

