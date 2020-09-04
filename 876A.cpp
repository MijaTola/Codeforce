#include <bits/stdc++.h>

using namespace std;

int v[0];
bool b[0];
int main(){
    
    int n;
   
    cin >> n;

    for (int i = 0; i < 3; ++i)
        cin >> v[i];
    
    int ans = 0;
    int cur = 0;
    
    int p = 1;
    while(p < n){
        p++;
        int mn = 1e9;
        int id = -1;
        for (int j = 0; j < 3; ++j){
            if(j == cur) continue;
            if(v[j] < mn){
                mn = v[j];
                id = mn;
            }
        }
        ans += mn;
        cur = id;
    }
    cout << ans << "\n";
    return 0;
}

