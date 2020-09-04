#include <bits/stdc++.h>

using namespace std;

int a[30];
char v [] = {'A', 'C', 'T', 'G'};

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 1e9;
    for (int i = 0; i < n - 3; ++i) {
        int sum = 0;
        for (int j = i, p = 0; j < i + 4; j++, p++) {
            int c = 0, c2 = 0;
            int to = v[p] - 'A';
            int from = s[j] - 'A';
            while(from != to) {
                from = (from + 1) % 26;
                c++;
            }
            to = v[p] - 'A';
            from = s[j] - 'A';
            while(from != to) {
                from = (from - 1 + 26) % 26;
                c2++;
            }
            int cur = min(c,c2);
            sum += cur;
        }
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}
