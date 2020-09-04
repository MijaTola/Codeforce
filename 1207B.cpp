#include <bits/stdc++.h>

using namespace std;

int a[55][55];
int b[55][55];
int n,m;
vector<pair<int,int> > ans;
bool check(int x,int y) {
    return a[x][y] + a[x + 1][y] + a[x][y + 1] + a[x + 1][y + 1] == 4
        and x >= 0 and x < n and x + 1 < n and y >= 0 and y < m and y + 1 < m;
}

void setM(int x,int y) {
    ans.push_back({x,y});
    b[x][y] = b[x + 1][y] = b[x][y + 1] = b[x + 1][y + 1] = 1;
}

int main() {
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if(check(i,j)) setM(i,j);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            if(a[i][j] != b[i][j]) return cout << "-1\n",0;
    
    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first + 1 << " " << p.second + 1<< "\n";
    return 0;
}

