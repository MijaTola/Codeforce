#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,b,c;
    cin >> a >> b >> c;
    
    int ans = 1e9;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                int da = a + i;
                int db = b + j;
                int dc = c + k;
                if(da + db > dc and da + dc > db and db + dc > da) {
                    int cur = i + j + k;
                    ans = min(ans, cur);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

