#include <bits/stdc++.h>

using namespace std;

set< pair<pair<int,int>, int> > s;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int cur = j ^ i;
            int a = i;
            int b = j;
            int c = cur;
            if(c < a or c < b) continue;
            if(c > n) continue;
            if(a + b > c and a + c > b and b + c > a) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

