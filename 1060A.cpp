#include <bits/stdc++.h>

using namespace std;

int v[10];
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) 
        v[s[i] - '0']++;
    
    int ans = 0;
    for (int i = 0; i < n; ++i) 
        ans += v[i];

    int p = v[8];

    while((ans - p) < p * 10 and p)p--;
    cout << p << "\n";
    return 0;
}

