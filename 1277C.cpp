#include <bits/stdc++.h>

using namespace std;

string s;
bool vis[2000010];


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;


    auto check = [] (vector<int> v) {
        for (int pos: v)
            if(vis[pos]) return 0;
        return 1;
    };
    while(t--) {
        cin >> s;

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < (int)s.size(); ++i) {
            vis[i] = 0;
            if(s[i] == 'o') q.push(i);
        }


        while(!q.empty()) {
            int u = q.front();
            q.pop();

            int l = u - 2;
            int l1 = u - 1;

            int r1 = u + 1;
            int r = u + 2;

            if(l >= 0 and l1 >= 0 and r1 < (int)s.size()  and r < (int)s.size()) {
                if(s[l] == 't' and s[l1] == 'w' and s[r1] == 'n' and s[r]== 'e' and check({l, l1, r1, r})) {
                    vis[l] = vis[l1] = vis[r1] = vis[r] = 1;
                    ans.push_back(u);
                }
            }

        }

        for (int i = 0; i < (int)s.size() - 2; ++i) {
            if(s[i] == 'o' and s[i + 1] == 'n' and s[i + 2] == 'e' and check({i, i + 1, i + 2})) {
                ans.push_back(i + 1);
                vis[i] = vis[i + 1] = vis[i + 2] = 1;
            }

            if(s[i] == 't' and s[i + 1] == 'w' and s[i + 2] == 'o' and check({i, i + 1, i + 2})) {
                ans.push_back(i + 1);
                vis[i] = vis[i + 1] = vis[i + 2] = 1;
            }

        }

        cout << ans.size() << "\n";
        for (int x: ans)
            cout << x + 1 << " ";
        cout << "\n";
    }
    return 0;
}
