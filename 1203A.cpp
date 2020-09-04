#include <bits/stdc++.h>

using namespace std;

int v[210];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        int id = -1;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if(v[i] == 1) id = i;
        }
        
        bool flag = 1;
        for (int i = id; i < id + n - 1; ++i) 
            flag &= (v[i % n] + 1 == v[(i + 1) % n]);
            
        if(flag) {
            cout << "YES\n";
            continue;
        }
        flag = 1;
        for (int i = id; i > id - n + 1; --i) 
            flag &= (v[(i + n) % n] + 1 == v[((i - 1) + n)% n] );
        
        if(flag) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }

    return 0;
}

