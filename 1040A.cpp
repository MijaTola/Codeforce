#include <bits/stdc++.h>

using namespace std;

int v[30];
bool buy[30];

int main(){
    memset(buy,0,sizeof buy);
    int n,a,b; cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] != 2) buy[i] = 1;
    }
    
    
    for (int i = 0; i < n; ++i) {
        if(v[i] != 2 and v[n - (i + 1)] != 2 
                and v[i] != v[n - (i + 1)])
            return cout << "-1\n",0;
    }
    
    for (int i = 0; i < n; ++i) {
        if(v[i] == 2) {
            if(v[n - (i + 1)] == 2)
                v[i] = v[n - (i + 1)] = (a < b) ? 0:1;
            else v[i] = v[n - (i + 1)];
        }
    }

    if(n & 1 and v[(n + 1)/ 2] == 2) v[(n + 1) / 2] = (a < b) ? 0 : 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) 
        if(!buy[i])ans += v[i] == 0 ? a : b;
    
    cout << ans << "\n";
    //1 2 3 4 5 6 7 8
    return 0;
}
