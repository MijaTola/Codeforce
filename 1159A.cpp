#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 1e9;
    for (int i = 0; i <= 1000; ++i) {
        int pile = i;

        for (int j = 0; j < n; ++j) {
            if(s[j] == '-') pile--;
            else pile++;
            if(pile < 0) {
                pile = 1e9;
                break;
            }
        }
        ans = min(ans, pile);
    }
    cout << ans << "\n";
    return 0;
}

