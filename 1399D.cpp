#include <bits/stdc++.h>

using namespace std;

int vis[1000010];

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        set<int> a,b;
        for (int i = 0; i < n; ++i) {
            vis[i] = 0;
            if(s[i] == '1') b.insert(i);
            else a.insert(i);
        }
        a.insert(n);
        b.insert(n);
        int color = 0;
        for (int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            color++;
            vis[i] = color;
            int flag = s[i] - '0';
            int pos = i;
            while(pos < n) {
                if(flag) {
                    auto it = *a.upper_bound(pos);
                    if(it >= 0 and it < n) {
                        vis[it] = color;
                        a.erase(it);
                        pos = it;
                    } else break;
                } else {
                    auto it = *b.upper_bound(pos);
                    if(it >= 0 and it < n) {
                        vis[it] = color;
                        b.erase(it);
                        pos = it;
                    } else break;
                }
                flag = 1 - flag;
            }
        }

        cout << color << "\n";

        for (int i = 0; i < n; ++i)
            cout << vis[i] << " ";
        cout << "\n";
    }
    return 0;
}
