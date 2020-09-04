#include <bits/stdc++.h>

using namespace std;

char da[200010];

int main() {
    int k;
    string s,t;
    cin >> k >> s >> t;
    int c = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        da[i] = (s[i] + t[i] + c) % 26;

        c = (s[i] + t[i] + c) / 26;
    }

    for (int i = 0; i < k; ++i) {
    }
    cout << "\n";
    return 0;
}

