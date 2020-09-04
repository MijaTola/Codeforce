#include <bits/stdc++.h>

using namespace std;

string s;
int foward[1000010];
int backward[1000010];
int vis[10000010];

int main() {
    
    for (int i = 0; i < 1000010; ++i) {
        foward[i] = i + 1;
        backward[i] = i - 1;
    }

    cin >> s;

    queue<int> q;

    auto check = [&] (int i) {
        bool flag = 0;
        if(i) flag |= s[i - 1] != s[i];
        if(i + 1 < (int)s.size()) flag |= s[i + 1] != s[i];
        return flag;
    };

    for (int i = 0; i < (int)s.size(); ++i) {
        if(check(i)) {
            q.push(i);
            vis[i] = 1;
        }
    }

    bool flag = q.size() != 0;
    int ans = 0;

    while(flag) {
        flag = 0;
        ans++;
        queue<int> q2;
        while(!q.empty()) {
            int pos = q.front();
            q.pop();
            if(vis[pos] == 2) continue;
            vis[pos] = 2;

            int back = backward[pos];
            int frwd = foward[pos];

            if(back >= 0) foward[back] = frwd;
            backward[frwd] = back;
            
            if(back >= 0 and frwd < (int)s.size()) {
                if(s[back] != s[frwd] and !vis[frwd]) {
                    flag = 1;
                    vis[back] = vis[frwd] = 1;
                    q2.push(back);
                    q2.push(frwd);
                }
            }

        }
        q = q2;
    }

    cout << ans << "\n";

    return 0;
}

