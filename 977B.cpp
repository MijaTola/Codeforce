#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int n; cin >> n;
    cin >> s;
    map<string,int> mp;
    for (int i = 1; i < (int)s.size(); ++i) {
        char a = s[i - 1];
        char b = s[i];
        string da = "";
        string db = "";
        da += a;
        db += b;
        mp[da + db]++;
    }

    string ans = "";
    int mx = 0;

    for (pair<string,int> p: mp) {
        if(p.second > mx) {
            mx = p.second;
            ans = p.first;
        }
    }
    cout << ans << "\n";
    return 0;
}

