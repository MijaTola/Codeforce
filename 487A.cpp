#include <bits/stdc++.h>

using namespace std;

int main() {
    int hy,ay,dy,hm,am,dm,h,a,d;
    cin >> hy >> ay >> dy;
    cin >> hm >> am >> dm;
    cin >> h >> a >> d;

    int n = 300;
    int ans = 1e9;
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            int cay = ay + j;
            int cdy = dy + k;
            int damageY = max(cay - dm,0);
            int damageM = max(0, am - cdy);
            if(!damageY) continue;
            int hits = hm / damageY + (hm % damageY != 0);
            int hp = damageM * hits;
            int toBuy = max(0, hp - hy + 1);
            ans = min(ans, j * a + d * k + toBuy * h);

        }   
    }
    cout << ans << "\n";
    return 0;
}

