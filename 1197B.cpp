#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main() {
    
    int n;
    cin >> n;
    int mx = 0;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] > mx) {
            mx = v[i];
            id = i;
        }
    }

    bool flag = 1;
    for (int i = id + 1; i < n; ++i) 
        flag &= v[i] < v[i - 1];

    for (int i = id - 1; i >= 0; i--)
        flag &= v[i] < v[i + 1];
    
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    
    //1 30 100 101 102
    return 0;
}

