#include <bits/stdc++.h>

using namespace std;


set<pair<int,int> > a;
set<pair<int,int> > b;
int main(){
    int n,m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        int x,y; cin >> x >> y;
        a.insert({max(x,y),min(x,y)});
    }

    for (int i = 0; i < n; ++i) {
        int x,y; cin >> x >> y;
        b.insert({max(x,y),min(x,y)});
    }
    
    int c = 0;
    int ans = -1;
    for (pair<int,int> da: a) {
        for (pair<int,int> db: b) {
            int fa = da.first;
            int sa = da.second;
            int fb = db.first;
            int sb = db.second;
        
            cout << sa << " "<<sb << " " << fa << " " << fb << "\n";
            if(fa == fb and sa != sb) {
                ans = fa;
                c++;
            }
            if(fa == sb and sa != fb) {
                ans = fa;
                c++;
            }

            if(sa == fb and fa != sb) {
                ans = sa;
                c++;
            }
            if(sa == sb and fa != fb) {
                ans = sa;
                c++;
            }
        }
    }

    if(ans == -1) cout << ans << "\n";
    else if(c == 1) cout << ans << "\n";
    else cout  << "0\n";
    return 0;
}

