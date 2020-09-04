#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    
    int t;
    cin >> t;

    while(t--) {
        set<int> s;
        int n,x;
        cin >> n >> x;

        bool flag = 0;
        bool bigger = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            s.insert(v[i]);
            flag |= v[i] == x;
            bigger |= v[i] > x;
        }

        if(flag) {
            cout << "1\n";
            continue;
        }
        
        if(bigger) {
            cout << "2\n";
            continue;
        }
        sort(v, v + n);
        reverse(v, v + n);
        int ans = x / v[0] + (x % v[0] != 0);
        cout << ans << "\n";



        
    }
    return 0;
}

