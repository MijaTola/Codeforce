#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {

    int t;

    cin >> t;

    while(t--) {
        cin >> n >> s;

        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] == '(') sum++;
            else sum--;
            if(sum < 0) ans++,sum++;
        }

        cout << ans << "\n";

    }
    return 0;
}

