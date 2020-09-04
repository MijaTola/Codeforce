#include <bits/stdc++.h>

using namespace std;

int dy[500010];

int main() {
    
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    auto ver = [&] (int x, int y) {
        int z = x + y - 1;
        return c <= z and z <= d;
    };

    long long ans = 0;
    for (int i = a; i <= b; ++i) {
        int l = b - 1, r = c;

        while(r - l > 1) {
            int mid = (r + l) / 2;
            if(ver(i, mid)) r = mid;
            else l = mid;
        }
        if(!ver(i,r)) continue;
        long long z = i + r - 1;
        long long can = z - c + 1;
        long long fin = can + (c - r);
        long long cur = fin * (fin + 1) / 2;
        can--;
        cur -= can * (can + 1) / 2;
        ans += cur;
    }

    cout << max(1ll,ans) << "\n";
    return 0;
}

