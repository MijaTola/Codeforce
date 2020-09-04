#include <bits/stdc++.h>

using namespace std;

int main(){
    
    /*int n,m; cin >> n >> m;
    int p = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%5d ",p);
            p++;
        }
        cout << "\n";
    }*/

    int n; cin >> n;
    
    int d = -1;
    int last = -1;
    int mx = 0; 
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(last == -1) last = x;
        else {
            if(last < x) {
                if(x == last + 1) last = x;
                else {
                    if(d == -1) d = abs(last - x);
                    else if(d != abs(last - x)) return cout << "NO\n",0;
                    last = x;
                }
            }else if(last > x) {
                if(last - 1 == x) last = x;
                else if(d == -1) d = abs(last-  x) ;
                else if(d != abs(last - x)) return cout << "NO\n",0;
                last = x;
            }
        }
        mx = max(mx,x);
    }
    if(n == 1) return cout << "YES\n" << 1000000000 << " " << 1000000000 << "\n",0;
    int r = (mx + 1) / d;
    if(r < 0 or d < 0) return cout << "NO\n",0;
    cout << "YES\n";
    if(r < 1e9) r++;
    cout << r  << " " << d << "\n";
    return 0;
}

