#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n,a,b;
    cin >> n >> a >> b;
    int da = min(a,b);
    int db= max(a,b);
    a = da;
    b = db;
    int round = 0;
    bool f = 0;
    for (int i = 2; i <= n; i *= 2) {
        int cur = 0;
        round++;
        while(cur < n) {
            int x = cur + 1;
            int y = cur + i;
            if(x <= a and b <= y) {
                f = 1;
                break;
            }
            cur += i;
        }
        if(f) break;
    }
    if(pow(2,round) >= n or !f) cout << "Final!\n";
    else cout << round << "\n";

    return 0;
}

