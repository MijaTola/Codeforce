#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        int id = -1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x % 2 == 0) id = i + 1;
        }
        
        if(id == -1) {
            if(n == 1) cout << "-1\n";
            else cout << "2\n1 2\n";
        } else cout << "1\n"<< id << "\n";
    }
    return 0;
}

