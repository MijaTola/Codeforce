#include <bits/stdc++.h>

using namespace std;

vector<int> a,b,c;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x > 0) a.push_back(x);
        if(x < 0) b.push_back(x);
        if(x == 0) c.push_back(x);
    }

    long long ans = 0;

    for (int x: a) 
        ans += abs(x - 1);

    for (int x: b) 
        ans += -x - 1;

    if(b.size() % 2 != 0) {
        if(c.size()) {
            ans++;
            c.pop_back();
        } else {
            ans += 2;
        }
    }
    ans += c.size();
    cout << ans << "\n";
    return 0;
}

