#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    int u = 0;
    int d = 0;
    
    int last = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] == last) {
            if(v[i] == 1) u++;
            else d++;
        }else {
            ans = max(ans, min(u,d) * 2);
            if(v[i] == 1) u = 1, last = 1;
            else d = 1, last = 2;
        }
    }
            
    ans = max(ans, min(u,d) * 2);
    cout << ans  << "\n";
    return 0;
}

