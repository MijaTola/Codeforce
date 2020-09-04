#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> mp[2000010][2];
int v[300010];
int b[300010];

int bs(int x, int p, int ver) {
    int a = - 1;
    int b = mp[p][ver].size();
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(mp[p][ver][mid] >= x) b = mid;
        else a = mid;
    }
    return mp[p][ver].size() - b;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        b[i] = v[i];
    }
    
    mp[b[0]][0].push_back(0);
    for (int i = 1; i < n; ++i) {
        v[i] ^= v[i - 1];
        mp[v[i]][i & 1].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = b[i] ^ v[i];
        int val = bs(i + 1, cur, !(i & 1));
        ans += val;
    }
    cout << ans << "\n";
    return 0;
}
