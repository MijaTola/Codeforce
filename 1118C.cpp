#include <bits/stdc++.h>

using namespace std;

int n;
int a[11000];
int m[1000][1000];

void print() {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}

void build() {
    int b = 0;
    int t = n - 1;
    int pos = 0;
    while(b < t and b < n and t >= 0) {
        int l = 0, r = n - 1;
        while(l < r and l < n and r >= 0) {
            while((a[pos] <= 0 or a[pos] < 4) and pos < 1010) pos++;
            a[pos] -= 4;
            m[l][b] = pos;
            m[l][t] = pos;
            m[r][t] = pos;
            m[r][b] = pos;
            l++, r--;
        }
        b++,t--;
    }

    int l = 0; int r = n - 1;
    int mid = (n) / 2;
    pos = 0;
    while(l < r and l < n and r >= 0) {
        if(m[l][mid] != 0 or m[r][mid] != 0) {
            l++,r--;
            continue;
        }
        while((a[pos] <= 0  or a[pos] <= 1) and pos < 1010) pos++;
        if(pos ==  1010) break;
        m[l][mid] = pos;
        m[r][mid] = pos;
        a[pos] -= 2;
        l++, r--;
    }
    pos = 0;
    l = 0, r = n - 1;
    while(l < r and l < n and r >= 0) {
        if(m[mid][l] != 0 or m[mid][r] != 0) {
            l++,r--;
            continue;
        }
        while((a[pos] <= 0  or a[pos] <= 1) and pos < 1010 ) pos++;
        if(pos ==  1010) break;
        m[mid][l] = pos;
        m[mid][r] = pos;
        a[pos] -= 2;
        l++, r--;
    }
    pos = 0;
    while(a[pos] <= 0 and pos < 1010) pos++;
    if(pos == 1010) return;
    if(m[mid][mid] == 0) {
        m[mid][mid] = pos;
        a[pos]--;
    }
}

bool ver() {
    for (int i = 0; i < 1010; ++i)
        if(a[i] > 0) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x; a[x]++;
    }

    build();
    if(ver())print();
    else cout << "NO\n";
    return 0;
}
