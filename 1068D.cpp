#include <bits/stdc++.h>

using namespace std;

int v[100010];
int n;
int f(int pos, int last, bool flag) {
    if(pos == n) return 1;
    int ans = 0;
    if(v[pos] != -1) {
        if(!flag) ans += f(pos + 1, v[pos], last < v[pos]);
        else if(v[pos] >= last) ans += f(pos + 1, v[pos], 1);
    } else {
        for (int i = 1; i <= 200; ++i) {
            if(!flag) ans += f(pos + 1, i, last < i);
            else if(i >= last) ans += f(pos + 1, i, 1);
        }
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << f(0,0,0) << "\n";
    
    return 0;
}

