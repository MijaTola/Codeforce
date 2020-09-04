#include <bits/stdc++.h>

using namespace std;

char c[110][110];
bool vis[110][110];
int n,m;
vector<pair<int,pair<int,int> > > ans;
int main(){
    memset(vis,false,sizeof vis);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
        }
    }

    bool ver = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == '.') {
                vis[i][j] = 1;
                continue;
            }
            ver = 1;
            int r = 1;
            bool flag = 1;
            while(flag and r < n and r < m) {
                flag = 0;
                if( i + r < n and i - r >= 0
                and j + r < m and j - r >= 0
                and c[i + r][j] == '*'
                and c[i - r][j] == '*'
                and c[i][j + r] == '*' 
                and c[i][j - r] == '*') flag = 1;
                if(flag) r++;
            }
            r--;
            if(r == 0) continue;
            vis[i][j] = 1;
            ans.push_back({i,{j,r}});
            for (int k = 1; k <= r; ++k) {
                vis[i + k][j] = 1;
                vis[i - k][j] = 1;
                vis[i][j + k] = 1;
                vis[i][j - k] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if(!vis[i][j]) return cout << "-1\n",0;
    
    if(!ver) return cout << 0 << "\n",0;
    if(ans.size() == 0) return cout << "-1\n",0;
    cout << ans.size() << "\n";

    for (int i = 0; i < (int)ans.size(); ++i) 
        cout  << ans[i].first + 1 << " " << ans[i].second.first  + 1 << " "<< ans[i].second.second << "\n";
    
    return 0;
}

