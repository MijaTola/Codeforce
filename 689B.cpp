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

using namespace std;

typedef long long ll;

vector<int > G[200010];
int d[200010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        G[i].push_back(x);
        if(i+1 <= n){
            G[i].push_back(i+1);
            G[i+1].push_back(i);
        }

    }
    
    q.push(1);
    memset(d,-1,sizeof d);
    d[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i: G[u]){
            if(d[i] == -1){
                d[i] = d[u]+1;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << d[i] << " ";
    return 0;
}

