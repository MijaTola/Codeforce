#include <bits/stdc++.h>

using namespace std;

int vis[100010];
int vis2[100010];
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            vis[i] = vis2[i] = 0;

        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            bool flag = 0;
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                x--;
                if(!vis[x] and !flag) {
                    vis[x] = vis2[i] = 1;
                    flag = 1;
                }
            }
        }

        bool check = 1;

        for (int i = 0; i < n; ++i)
            check &= vis2[i] == 1;
        
        if(check) {
            cout << "OPTIMAL\n";
            continue;
        }

        cout << "IMPROVE\n";

        for (int i = 0; i < n; ++i)
            if(!vis2[i]) {
                cout << i + 1<< " ";
                break;
            }

        for (int i = 0; i < n; ++i)
            if(!vis[i]) {
                cout << i + 1 << "\n";
                break;
            }
    }
    return 0;
}

