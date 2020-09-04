#include <bits/stdc++.h>

using namespace std;

int a[30];
int b[30];

int main() {

    int t;
    cin >> t;
    while(t--) {
        memset(a, 0, sizeof a);
        string x,y;
        cin >> x >> y;
        
        for (int i = 0; i < (int)x.size(); ++i) 
            a[x[i] - 'a']++;
        
    
        bool flag = 0;
        for (int i = 0; i < (int)y.size() - (int)x.size() + 1; ++i) {
            memset(b, 0, sizeof b);
            for (int j = 0, p = i; j < (int)x.size(); ++j, p++) {
                b[y[p] - 'a']++;
            }

            bool is = 1;
            for (int j = 0; j < 30; ++j) {
                is &= a[j] == b[j];
            }

            flag |= is;
        }

        cout << (flag ? "YES" : "NO") << "\n";
        
    }
    return 0;
}

