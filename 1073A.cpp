#include <bits/stdc++.h>

using namespace std;

int a[27];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {

            memset(a, 0, sizeof a); 
            for (int k = i; k <= j; ++k) 
                a[s[k] - 'a']++;

            bool flag = 1;
            for (int k = 0; k < 27; ++k) 
                flag &= (a[k] <= (j - i + 1) / 2);

            if(flag) {
                cout << "YES\n";
                for (int k = i; k <= j; ++k) 
                    cout << s[k];
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    
    return 0;
}

