#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string p = "BGR";
vector<string> per;
int main() {
    do {
        per.push_back(p);
    } while(next_permutation(p.begin(), p.end()));
    cin >> n >> s;
    
    int ans = 1e9;
    string sans = "";
    for (int i = 0; i < (int)per.size(); ++i) {
        string t = "";
        while((int)t.size() < n) t += per[i];
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] != t[i]) cnt++;
        }
        if(cnt < ans) {
            ans = cnt;
            sans = t;
        }
    }
    cout << ans << "\n";

    for (int i = 0; i < n; ++i)
        cout << sans[i];
    cout << "\n";
    return 0;
}

