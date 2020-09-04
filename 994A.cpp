#include <bits/stdc++.h>

using namespace std;

int v[10];
int b[10];
int main(){
    int n,m;   
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(b, b + m);
    reverse(b, b + m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(b[j] == v[i]) {
                cout << b[j] << " ";
            }
        }
    }
    cout <<"\n";
    return 0;
}

