#include <bits/stdc++.h>

using namespace std;

char c[2010][2010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            cin >> c[i][j];
    
    if(n == 1 and m == 1 and k == 1) return cout << "1\n",0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == '.') {
                cur++;
            } else {
                if(cur >= k) {
                    int r = cur - k;
                    ans += r + 1;
                }
                cur = 0;
            }
        }
        if(cur != 0 and cur >= k) {
            int r = cur - k;
            ans += r + 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if(c[j][i] == '.') cur++;
            else {
                if(cur >= k) {
                    int r = cur - k;
                    ans += r + 1;
                }
                cur = 0;
            }
        }
        if(cur != 0 and cur >= k) {
            int r = cur - k;
            ans += r + 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}

