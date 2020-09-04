#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main(){
    
    int n,k; cin >> n >> k;
    
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    sort(v, v + n);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int cur = v[i] + k;
        int pos = lower_bound(v, v + n, cur) - v;
        if(v[i] < v[pos] and v[i] + k >= v[pos] and i < pos and pos < n) 
            cnt++;
    }
    cout << n - cnt << "\n";
    return 0;
}

