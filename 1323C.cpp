#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    
    int sum = 0, ans = 0, cnt = 0;
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') {
            sum++;
        } else {
            sum--;
            if(sum < 0) flag = 1;
        }
        cnt++;
        if(sum == 0) {
            if(flag)ans += cnt, flag = 0;
            cnt = 0;
        }

    }

    if(sum != 0) return cout << "-1\n", 0;
    cout << ans << "\n";
    return 0;
}

