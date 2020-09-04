#include <bits/stdc++.h>

using namespace std;

int v[5010];

int main(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    
    for (int i = 1; i <= n; ++i) {
        
        int x = v[i];
        int y = v[x];
        int z = v[y];
        int t = v[z];
        if(x == t) return  cout << "YES\n",0;
    }
    cout << "NO\n";
    return 0;
}

