#include <bits/stdc++.h>

using namespace std;

int v[200010];
int n,m;
int main(){
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    int left = 0;
    for (int i = 0; i < n; ++i) {
        cout << (v[i] + left) / m << "\n";
        left = (v[i] + left) % m;
    }
    
    return 0;
}
