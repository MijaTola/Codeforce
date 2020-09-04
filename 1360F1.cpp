#include <bits/stdc++.h>

using namespace std;

int t;
int n,m;
string v[11];

int dp[11][1 << 11];

int f(int pos, int mask) {
    if(pos == m) return 1;
    
    int &ans = dp[pos][mask];

    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0 ; i < 26; ++i) {
        char c = i + 'a';
        bool flag = 1;
        int copia = mask;
        for (int j = 0; j < n; ++j) 
            if(c != v[j][pos]) {
                if(mask & (1 << j)) flag = 0;
                else copia |= (1 << j);
            }
           
        if(flag) ans |= f(pos + 1, copia);
    }
    return ans;
}

void r(int pos, int mask) {
    
    if(pos == m) return;

    for (int i = 0; i < 26; ++i) {
        char c = i + 'a';

        bool flag = 1;
        int copia = mask;

        for (int j = 0; j < n; ++j) 
            if(c != v[j][pos]) {
                if(mask & (1 << j)) flag = 0;
                else copia |= (1 << j);
            }
        
        if(flag) {
            if(f(pos + 1, copia) ) {
                cout << c;
                r(pos + 1, copia);
                break;
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;

    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            cin >> v[i];


        if(!f(0,0)) {
            cout << "-1\n";
            continue;
        }

        r(0, 0);
        cout << '\n';
    }

    return 0;
}

