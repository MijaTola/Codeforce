#include <bits/stdc++.h>

using namespace std;

//a 0 3 6
//b 1 5
//c 2 4
//           l m m j v s d l m m j v s d
int da [] = {1,0,0,1,0,0,1,1,0,0,1,0,0,1};
int db [] = {0,1,0,0,0,1,0,0,1,0,0,0,1,0};
int dc [] = {0,0,1,0,1,0,0,0,0,1,0,1,0,0};
int a,b,c;

bool ver(long long d, int ini) {
    long long w = d / 7;
    long long ta = w * 3;
    long long tb = w * 2;
    long long tc = w * 2;
    for (int i = 0; i < d % 7; ++i) {
        ta += da[ini + i];
        tb += db[ini + i];
        tc += dc[ini + i];
    }
    return ta <= a and tb <= b and tc <= c;
}
int main() {
    ios::sync_with_stdio(false); cin.tie();
    cin >> a >> b >> c;
    long long  ans = 0;
    for (int i = 0; i < 7; ++i) {
        long long l = 0;
        long long r = 1e10;
        while(r - l > 1) {
            long long mid = (r + l) / 2;
            if(ver(mid, i)) l = mid;
            else r = mid;
        }
        ans = max(ans, l);
    }
    cout << ans << "\n";
    return 0;
}

