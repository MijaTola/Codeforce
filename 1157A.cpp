#include <bits/stdc++.h>

using namespace std;

set<int> s;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    while(!s.count(n)) {
        s.insert(n);
        n++;
        ans++;
        while(n % 10 == 0) n /= 10;
    }
    cout << ans << "\n";
    return 0;
}

