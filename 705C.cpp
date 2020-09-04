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

using namespace std;

typedef long long ll;

vector<int> apps[300100];
int readed[300100];
int main(){
    //ios::sync_with_stdio(false); cin.tie(0);
    int n,q; cin >> n >> q;
    int total = 0;
    int pos = 0;
    while(q--){
        int c,t;// cin >> c >> t;
        scanf("%d %d",&c,&t);
        if(c == 1){apps[t].push_back(++pos); total++;}
        if(c == 2){
            total -= apps[t].size() - readed[t];
            readed[t] = apps[t].size();
        }
        if(c == 3){
            for (int i = 1; i <= n; ++i){
                int j;
                for (j = readed[i]; j < (int)apps[i].size() and apps[i][j] <= t; ++j){
                    total--;
                }
                readed[i] = j;
            }
        }
        printf("%d\n",total);
    }
    return 0;
}

