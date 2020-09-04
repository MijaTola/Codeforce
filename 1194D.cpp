#include <bits/stdc++.h>

using namespace std;

int mod[] = {0,1,1};
int nmod[] = {0,1,1,1};

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        if(k % 3 != 0) {
            int p = n % 3;
            if(mod[p]) cout << "Alice\n";
            else cout << "Bob\n";
        } else {
            int dv = k / 3;
            int cur = (dv - 1) * 3 + 4;
            int p = n % cur;
            int len = (dv - 1) * 3;
            if(p <= len - 1) {
                p = p % 3;
                if(mod[p]) cout << "Alice\n";
                else cout << "Bob\n";
            } else {
                p -= len;
                if(nmod[p]) cout << "Alice\n";
                else cout << "Bob\n";
            }

        }
    }
    return 0;
}

