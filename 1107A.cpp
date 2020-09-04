#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    while(n--) {
        
        int p;
        cin >> p;
        string x;
        cin >> x;
        if(p == 2) {
            if(x[0] < x[1]) {
                puts("YES\n2");
                cout << x[0] << " " << x[1] << "\n";
                
            } else puts("NO");
            continue;
        } else {
            puts("YES\n2");
            cout << x[0] << " ";
            for (int i = 1; i < (int)x.size(); ++i)
                cout << x[i];
            cout << "\n";
        }
    }
    return 0;
}

