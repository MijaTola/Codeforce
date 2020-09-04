#include <bits/stdc++.h>

using namespace std;

int v[1100];
int b[1110];
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> v[i];

        sort(v, v + n);
        int ans = -1;

        for (int i = 1; i < 1500; ++i) {

            for (int j = 0; j < n; ++j) {
                b[j] = v[j] ^ i;
            }

            sort(b, b + n);
            bool flag = 1;
            for (int j = 0; j < n; ++j) {
                //cout << b[j] << " " << v[j] << "\n";
                flag &= b[j] == v[j];
            }

            if(flag) {
                ans = i;
                break;
            }
        }

        cout << ans << "\n";

    }
    return 0;
}

