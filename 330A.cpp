#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    char v[11][11];
    while(cin >> n >> m){
        bool x[11];
        bool y[11];
        memset(x,false,sizeof x);
        memset(y,false,sizeof y);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> v[i][j];
                if(v[i][j] == 'S'){
                    x[i] = true; y[j] = true;
                }
            }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if(x[i]) continue;
            else{
                for (int j = 0; j < m; ++j)
                {
                    if(v[i][j] != 'E'){
                        ans++;
                        v[i][j] = 'E';
                    }
                }}
        }
        for (int i = 0; i < m; ++i)
        {
            if(y[i]) continue;
            for (int j = 0; j < n; ++j)
            {
                if(v[j][i] != 'E'){
                    ans++;
                    v[j][i] = 'E';
                }
            }
        }
        cout << ans << endl;
    }
    /*for (int i = 0; i < n; ++i)
      {
      for (int j = 0; j < m; ++j)
      cout << v[i][j];
      cout << endl;
      }*/
    return 0;
}
