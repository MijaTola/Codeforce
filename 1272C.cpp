#include <bits/stdc++.h>

using namespace std;

bool a[27];
int main() {

    int n,k;
    string s;

    auto f = [] (long long x) {
        return x * (x - 1) / 2;
    };

    cin >> n >> k >> s;

    for (int i = 0; i < k; ++i) {
        char x;
        cin >> x;
        a[x - 'a'] = 1; 
    }

    int c = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if(a[s[i] - 'a']) c++;
        else {
            ans += f(c) + c;
            c = 0;
        }
    }

    ans += f(c) + c;
    cout << ans << "\n";
    return 0;
}

