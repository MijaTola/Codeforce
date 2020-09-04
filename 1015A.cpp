#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int v[110];
int main(){
    
    int n,m; cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x,y; 
        cin >> x >> y;
        for (int j = x; j <= y; ++j)
            v[j] = 1;
    }
    
    for (int i = 1; i <= m; ++i) {
        if(!v[i]) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}

