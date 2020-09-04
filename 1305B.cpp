#include <bits/stdc++.h>

using namespace std;

int a[1010];
int b[1010];
bool vis[1010];
string s;
int main() {

    cin >> s;
    
    vector<vector<int> > ans;
    while(1) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(vis, 0, sizeof vis);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if(s[i] == '(') a[i] = 1;
            if(s[i] == ')') b[i] = 1;
        }

        for (int i = 1; i < n; ++i)
            a[i] += a[i - 1];

        for (int i = n - 1; i >= 0; i--)
            b[i] += b[i + 1];


        int mx = 0;
        int id = -1;

        for (int i = 0; i < n; ++i) {
            int mn = min(a[i], b[i + 1]);
            if(mn > mx) {
                mx = mn;
                id = i;
            }
        }
        if(id == -1) break;
        vector<int> cur;
        for (int i = 0; i <= id and (int)cur.size() < mx; ++i) 
            if(s[i] == '(') {
                cur.push_back(i);
                vis[i] = 1;
            }
        
        for (int i = n - 1, cnt = 0; i > id and cnt < mx  ; --i) {
            if(s[i] == ')') {
                cur.push_back(i);
                vis[i] = 1;
                cnt++;
            }
        }
        sort(cur.begin(), cur.end());
        ans.push_back(cur);
        string t =  "";

        for (int i = 0; i < n; ++i)
            if(!vis[i]) t += s[i];
        s = t;
    }

    cout << ans.size() << "\n";

    for (auto v: ans)  {
        cout << v.size() << "\n";   
        for (int x: v)
            cout << x + 1 << " ";
        cout << "\n";
    }
    return 0;
}

