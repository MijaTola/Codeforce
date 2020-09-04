#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        long long a,b,n,m;
        cin >> a >> b >> n >> m;
    
        bool flag = 0;
        if(a + b >= n + m) {
            if(a > b) {
                int df = a - b;
                if(df <= n) {
                    n -= df;
                    a = b;
                } else {
                    a -= n;
                    n = 0;
                    if(a > b) {
                        if(b >= m) flag = 1;
                    }
                }

            }
            if(b > a) {
                int df = b - a;
                if(df <= n) {
                    n -= df;
                    b = a;
                } else {
                    b -= n;
                    n = 0;
                    if(b >= a) {
                        if(a >= m) flag = 1;
                    }
                }
            }
            

            if(a >= max(n,m)) flag = 1;

        } 

        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

