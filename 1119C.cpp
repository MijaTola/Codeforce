#include <bits/stdc++.h>

using namespace std;

int rn[510];
int cn[510];
int rm[510];
int cm[510];
int n,m;

int a = 0, b = 0;
bool ver() {
    if(a % 2 != b % 2) return 0;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if(rn[i] % 2 != rm[i] % 2 or cn[j] % 2 != cm[j] % 2) 
                return 0;
    return 1;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            rn[i] += x;
            cn[j] += x;
            a += x;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            rm[i] += x;
            cm[j] += x;
            b += x;
        }
    }
    puts(ver() ? "YES" : "NO");
    return 0;
}

