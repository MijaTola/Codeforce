#include <bits/stdc++.h>

using namespace std;

int v[1000010];

int main() {
    
    int t;
    cin >> t;
    
    for (int i = 2; i < 1000010; ++i) {
        if(v[i]) continue;
        for (int j = i; j < 1000010; j += i)
            if(!v[j]) v[j] = i;
    }
    while(t--) {
        int n,k;
        cin >> n >> k;
        int total = (k - 1) * 2;
        cout << total + n + v[n] << "\n";
    }
    return 0;
}

