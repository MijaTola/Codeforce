#include <bits/stdc++.h>

using namespace std;

char c[110][110];
int a[110][110];
int main(){
    int n,m;   
    cin >> n >> m;
    int b = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            cin >> c[i][j];
            if(c[i][j] == 'B')b++;
        }
    if(b == 1) return cout << "0\n",0;
    if(b == 0) return cout <<"1\n",0;
    if((n == 1 and m > 1) or (m == 1 and n > 1)) return puts("-1"),0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(c[i][j] == 'B') a[i][j] = 1;
            if(i > 0) a[i][j] += a[i-1][j];
            if(j > 0) a[i][j] += a[i][j - 1];
            if(i > 0 and j > 0) a[i][j] -= a[i-1][j-1];
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            for (int l = 1; i + l < n; ++l){
                int di = l + i;
                int dj = l + j;
                if(dj >= m) continue;
                int cur = a[di][dj];
                if(i > 0) cur -= a[i - 1][dj];
                if(j > 0) cur -= a[di][j - 1];
                if(i and j) cur += a[i - 1][j - 1];
                if(cur == b){
                    //cout << i << " " << j<< " " << di << " " << dj << " "<< cur << " " << l + 1 << "\n";
                    cur = (l+1) * (l+1) - cur;
                    ans = min(cur,ans);
                }
            }
            for (int l = 1; j + l < m; ++l){
                int di = l + i;
                int dj = l + j;
                if(di >= n) continue;
                int cur = a[di][dj];
                if(i > 0) cur -= a[i - 1][dj];
                if(j > 0) cur -= a[di][j - 1];
                if(i and j) cur += a[i - 1][j - 1];
                if(cur == b){
                    //cout << i << " " << j<< " " << di << " " << dj << " " << cur << " " << l + 1 << "\n";
                    cur = (l + 1) * (l + 1) - cur;
                    ans = min(cur,ans);
                }
            }
        }
    }
    if(ans == 1e9) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

