#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n,k;
    cin >> n >> k;

    string s; cin >> s;
    sort(s.begin(),s.end());
    int p = 0;
    
    int d = -1e9;
    int ans = 0;
    int c = 0;
    while(p < (int)s.size() and c < k) {
        int d1 = s[p] - 'a';
        if(abs(d - d1) >= 2) {
            ans += (d1 + 1 );
            d = d1;
            c++;
        }
        p++;
    }
    if(c == k) cout << ans << "\n";
    else cout << "-1\n";
    return 0;
}

