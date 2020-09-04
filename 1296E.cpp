#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int a[200010];
int c[200010];

int main() {

    cin >> n >> s;

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        bool flag = 1;
        for (int j = 1; j <= ans; ++j) {
            if(c[j] <= s[i] - 'a') {
                flag = 0;
                a[i] = j;
                c[j] = s[i] - 'a';
                break;
            }

        }
        if(flag) {
            c[++ans] = s[i] - 'a';
            a[i] = ans;
        }
    }
    
    if(ans > 2) return puts("NO"), 0;

    cout << "YES\n";
    for (int i = 0; i < n; ++i) 
        cout << a[i] - 1;
    cout << "\n";
    return 0;
}

