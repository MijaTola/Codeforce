#include <bits/stdc++.h>

using namespace std;

char c[110][110];
int v[110][110];
int main(){

    int n,k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool v1 = 0;
            bool v3 = 0;
            for (int l = 0; l < k; ++l) {
                if(j + l >= n or (j + l < n and c[i][j + l] == '#')) v1 = 1; 
                if(i + l >= n or (i + l < n and c[i + l][j] == '#')) v3 = 1;
            }
            
            for (int l = 0; l < k; ++l) {
                if(j + l < n) v[i][j + l] += !v1;
                if(i + l < n) v[i + l][j] += !v3;
            }

        }
    }

    int dx = 1;
    int dy = 1;
    int mx = 0;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            if(v[i][j] > mx) {
                mx = v[i][j];
                dx = i + 1;
                dy = j + 1;
            }

    cout << dx << " " << dy << "\n";
    return 0;
}

