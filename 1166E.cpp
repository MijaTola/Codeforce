#include <bits/stdc++.h>

using namespace std;

int v[50][10010];
int n,m;
int main() {
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            v[i][x] = 1;
        }
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            bool flag = 0;
            for (int k = 0; k < n; ++k) 
                if(v[i][k] == v[j][k] and v[i][k]) 
                    flag = 1;
            if(!flag) return cout << "impossible\n",0;
        }
    }
    cout << "possible\n";
    return 0;
}

