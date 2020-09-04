#include <bits/stdc++.h>

using namespace std;

int v[510];

int main() {
    
    int q,n;
    cin >> q;
    while(q--) {
        cin >> n;

        for (int i = 0; i < 4 * n; ++i) 
            cin >> v[i];

        sort(v,v + 4 * n);
        
        int l = 0, r = 4 * n - 1;
        set<int> s;
        while(l + 1 < r - 1) {
            s.insert(v[l] * v[r]);
            if(v[l] != v[l + 1] or v[r] != v[r - 1]) s.insert(-1);
            l += 2,r -= 2;
        }
        
        if(s.size() == 1) puts("Yes");
        else puts("No");
        
    }
    return 0;
}
