#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0, ans = 0;
    string t = "";

    for (int i = 0; i < n; ++i) {
        if(s[i] == 'a') a++;
        else b++;

        if(i % 2 == 0) {
            t += s[i];
        } else {
            if(a > b) {
                a--;
                b++;
                t += "b";
                ans++;
            } else if(b > a){
                a++;
                b--;
                t += "a";
                ans++;
            } else t += s[i];
        }
    }
    cout << ans << "\n";
    cout << t << "\n";
    return 0;
}

