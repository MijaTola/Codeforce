#include <bits/stdc++.h>

using namespace std;

string s;
int n,t;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        if(s[0] == '>' or s[s.size() - 1] == '<') {
            cout << "0\n";
            continue;
        }
        
        int p = 0;
        int a = 0, b = 0;
        while(s[p] == '<' and p < n) {
            p++;
            a++;
        }
        p = n - 1;
        while(s[p] == '>' and p >= 0) {
            p--;
            b++;
        }
        cout << min(a,b) << "\n";
    }
    return 0;
}

