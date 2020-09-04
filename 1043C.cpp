#include <bits/stdc++.h>

using namespace std;

string s;
int ans[1010];

bool ver(string a, string b) {
    for (int i = 0 ; i < (int)b.size(); ++i) {
        if(a[i] < b[i]) return 1;
        if(a[i] > b[i]) return 0;
    }
    return 0;
}
int main() {

    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        if(s[0] == s[i + 1]) {
            ans[i] = 1;
            reverse(s.begin(), s.begin() + i + 1);
          }
    }
    string x  = s;
    reverse(x.begin(), x.end());
    if(ver(x,s))
        ans[n - 1] = 1;

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    return 0;
}
