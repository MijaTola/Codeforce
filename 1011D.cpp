#include <bits/stdc++.h>

using namespace std;

bool ans[31];
int main(){
    memset(ans, 0 ,sizeof ans);   
    int n,m;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cout << "1\n";
        fflush(stdout);
        int a;
        cin >> a;
        if(a == 0) return 0;
        if(a == 1) ans[i] = 1;
    }
    int p = 0;  
    int a = 0;
    int b = m;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        cout << mid << "\n";
        fflush(stdout);
        int r; cin >> r;
        if(r == 1) {
            if(ans[p]) a = mid;
            else b = mid;
        }
        if(r == -1) {
            if(ans[p]) b = mid;
            else a = mid;
        }
        if(r == 0) return 0;
        if(r == -2) return 0;
        p = (p + 1) % n;
    }

    cout << b << "\n";
    fflush(stdout);
    return 0;
}

