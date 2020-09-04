#include <bits/stdc++.h>

using namespace std;

int v[110];
int main(){
    
    int n,d;
    cin >> n >> d;

    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v,v + n);
    int mx = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int dd = abs(v[i] - v[j]);
            int cur = (n - 1)- (j - i);
            if(dd <= d and cur < mx) mx = cur;
        }
    }
    cout << mx << "\n";
    return 0;
}

