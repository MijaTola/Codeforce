#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n>> s;
    long long ans = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        int d = s[i] - '0';
        if(d % 2 == 0) 
            ans += (i + 1);
    }
    cout << ans << "\n";
    return 0;
}

