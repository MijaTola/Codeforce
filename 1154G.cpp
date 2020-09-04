#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v[10000010];
int mn[10000010];
int ids[10000010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 10000010; ++i)
        mn[i] = 1e9;
    cin >> n;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x].push_back(i);
        if(x == 1) id = i;
    }

    if(id != -1) {
        for (int i = 0; i < n; ++i)
            if(id != i) return cout << i + 1 << " " << id + 1 << "\n",0;
    }
    
    int ans = 1e9;
    int a1 = -1, a2 = -1;
    for (int i = 2; i < 10000010; ++i) {
        if(v[i].size() == 0) continue;

        for (int j = i; j < 10000010; j += i) {
            if(mn[j] != 1e9) {
                if(j < ans) {
                    a1 = v[i][0];
                    a2 = ids[j];
                    ans = j;
                }
            }
            mn[j] = i;
            ids[j] = v[i][0];
        }
    }
    if(a1 != -1)
        cout << min(a1,a2) + 1 << " " << max(a2,a1) + 1<< "\n";
    else cout << 1 << " " << 2 << "\n";

    return 0;
}

