#include <bits/stdc++.h>

using namespace std;

int v[110];

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> v[i];

        sort(v,v + n);
        vector<int> a,b;
        a.push_back(v[0]);
        for (int i = 1; i < n; ++i) {
            if(abs(a.back() - v[i]) > 1) {
                a.push_back(v[i]);
            } else b.push_back(v[i]);
        }
        
        cout << !a.empty() + !b.empty() << "\n";
    }
    return 0;
}

