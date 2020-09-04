#include <bits/stdc++.h>

using namespace std;

int v[100010];
int n;

int f(int pos, int cur, int dif) {
    if(pos == n) return 0;
    if(abs(cur - v[pos]) > 1) return 1e9;
    int ans = 1e9;
    ans = min(ans,f(pos + 1, cur + dif, dif) + (cur != v[pos]));
    ans = min(ans,f(pos + 1, cur - dif, dif) + (cur != v[pos]));
    return ans;
}
int main(){
    cin >> n; 

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    int ans = 1e9;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int a = v[0] + i;
            int b = v[1] + j;
            int dif = abs(b - a);
            int cur = (j != 0) + (i != 0);
            ans = min(ans,f(2, b + dif, dif) + cur);
            ans = min(ans,f(2, b - dif, dif) + cur);
        }
    }
    if(ans == 1e9) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}
