#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<pair<int,int> > ans;
    ans.emplace_back(0,0);
    ans.emplace_back(0,1);
    ans.emplace_back(1,0);

    int x = 1, y = 1;
    for (int i = 0; i < n; ++i) {
        ans.emplace_back(x,y);
        ans.emplace_back(x + 1,y);
        ans.emplace_back(x,y + 1);
        x++,y++;
    }

    ans.emplace_back(x,y);
    cout << ans.size() << "\n";

    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";

    return 0;
}

