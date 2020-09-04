#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        
        bool flag = 1;
        int t = 0;
        while(flag) {
            flag = 0;
            t++;
            for (int i = n - 2; i >= 0; i--) {
                if(s[i] == 'A') {
                    if(s[i + 1] == 'P') flag = 1;
                    s[i + 1] = 'A';
                }
            }
        }
        cout << t - 1 << "\n";
    }
    return 0;
}

