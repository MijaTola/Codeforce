#include <bits/stdc++.h>

using namespace std;

int pre[200010][27];
int al[27];

bool ver(int k) {
    for (int i = 0; i < 27; ++i) {
        if(al[i] == 0) continue;
        if(al[i] > pre[k][i]) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) 
        pre[i][s[i] - 'a'] = 1;
        
    for (int i = 1; i < n; ++i) 
        for (int j = 0; j < 27; ++j) 
            pre[i][j] += pre[i - 1][j];
        
    int m;
    cin >> m;
    while(m--) {
        memset(al, 0, sizeof al);
        string t;
        cin >> t;
        for (int i = 0; i < (int)t.size(); ++i) 
            al[t[i] - 'a']++;
        
        int a = -1, b = n; 

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) b = mid;
            else a = mid;
        }
        cout << b + 1<< "\n";
    }
    return 0;
}

