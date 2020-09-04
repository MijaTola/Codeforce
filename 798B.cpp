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

char s[55][55];
int n;
int main(){
    scanf("%d",&n);

    for (int i = 0; i < n; ++i)
        scanf("%s",s[i]);
    
    int sz = strlen(s[0]);
    int ans = INT_MAX;
    //igualar los strings con el string Si
    for (int i = 0; i < n; ++i){
        int moves = 0;
        for (int j = 0; j < n; ++j){
            if(i == j) continue;
            //buscar los movimientos para el match
            int cur = 0;
            bool match = false;
            for (int k = 0; k < sz; ++k){
                bool flag = true; //asumimos que esta opcion matchea
                for (int l = 0; l < sz; ++l){
                    if(s[i][l] != s[j][(l+k)%sz]) {flag = false; break;}//no match
                }
                if(flag){cur = k; match = true; break;}
            }
            if(!match) return puts("-1");
            moves += cur;
        }
        ans = min(ans,moves);
    }
    if(ans == INT_MAX) puts("-1");
    printf("%d\n",ans);
    
    return 0;
}

