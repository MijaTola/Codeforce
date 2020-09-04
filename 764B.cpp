#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int main() {

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int l = 0, r = n - 1;

    bool flag = 1;
    while(l < r) {
        if(flag) swap(v[l],v[r]);
        l++,r--;
        flag = !flag;
    }
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    
    return 0;
}

