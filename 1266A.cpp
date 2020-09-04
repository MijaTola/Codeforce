#include <bits/stdc++.h>

using namespace std;

int a[11];
int main() {

    int t;
    cin >> t;
    while(t--) {
        memset(a,0,sizeof a);
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            a[s[i] - '0']++;
            sum += s[i] - '0';
        }

        if((a[2] or a[4] or a[6] or a[8] or a[0] >= 2) and a[0] and sum % 3 == 0) cout << "red\n";
        else cout << "cyan\n";
    }
    return 0;
}

