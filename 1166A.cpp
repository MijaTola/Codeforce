#include <bits/stdc++.h>

using namespace std;

int v[27];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        v[s[0] - 'a']++;
    }

    int ans = 0;

    for (int i = 0; i< 27; ++i) {
        int a = v[i] / 2;
        int b = v[i] - a;
        ans += (a * (a - 1)) / 2;
        ans += (b * (b - 1)) / 2;
    }
    cout << ans << "\n";
    return 0;

}

