#include <bits/stdc++.h>

using namespace std;

int v[200010];
int n,k;

int main(){
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    if(k == 0) {
        if(v[0] == 1)return cout << "-1\n",0;
        else return cout << v[0] - 1 << "\n",0;
    }
    int ans = v[k - 1];
    int c = 0;
    for (int i = 0; i < n; ++i)
        if(v[i] <= ans) c++;
    if(c == k) cout << ans << "\n";
    else cout << "-1\n";
    return 0;
}
