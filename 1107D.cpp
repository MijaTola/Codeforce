#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int m[5210][5210];
int b[5210][5210];
bool vis[5210][5210];
unordered_map<char, string> mp;

bool ver(int x) {
    memset(vis, 0, sizeof vis);
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int di = floor((double)i / (double)x);
            int dj = ceil((double)j / (double)x);
            if(!vis[di][dj]) {
                vis[di][dj] = 1;
                b[di][dj] = m[i][j];
            } //else if(b[di][dj] != m[i][j]) return 0;
        }
    }
    cout << x << " x:\n";
    for (int i = 1; i <= n / x; ++i) {
        for (int j = 1; j <= n / x; ++j)
            cout << b[i][j];
        cout << "\n";
    }
    return 1;
}
int main() {
    mp['0'] = "0000"; mp['1'] = "0001"; mp['2'] = "0010";
    mp['3'] = "0011"; mp['4'] = "0100"; mp['5'] = "0101";
    mp['6'] = "0110"; mp['7'] = "0111"; mp['8'] = "1000";
    mp['9'] = "1001"; mp['A'] = "1010"; mp['B'] = "1011";
    mp['C'] = "1100"; mp['D'] = "1101"; mp['E'] = "1110";
    mp['F'] = "1111";

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        int c = 1;
        for (char x: s) 
            for (char y: mp[x]) 
                m[i][c++] = y - '0';
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << m[i][j];
        cout << "\n";
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if(ver(i)) mx = i;
    }
    cout << mx << "\n";
    return 0;
}

