#include <bits/stdc++.h>

using namespace std;

int v[110];
int ans[110];
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    
    int a = 0;
    int b = n - 1;
    bool flag = 1;
    for (int i = 0; i < n; ++i) {
        if(flag) ans[a++] = v[i];
        else ans[b--] = v[i];
        flag = !flag;
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

